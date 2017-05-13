#include"ChangeDrawColor.h"
#include "../Figures/CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager *pApp) :Action(pApp)
{}
void ChangeDrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose your desired Color");
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.x > UI.width / 2 - 100 && P1.x < UI.width / 2 + 100 && P1.y > UI.height / 2 - 75 && P1.y < UI.height / 2 + 75)
	{
		double Red, Green, Blue;
		Red = 0;
		Green = 0;
		Blue = 0;
		pOut->getclickedcolor(Red, Green, Blue, P1.x, P1.y);
		Red   = Red * 255;
		Green = Green * 255;
		Blue  = Blue * 255;
		color Clicked = color((unsigned char)Red, (unsigned char) Green, (unsigned char) Blue);
	
		if (Red == 255 && Green == 0 && Blue == 255)
		{
			pOut->PrintMessage("Invalid Color");
			return;
		}
		else
		{
			CFigure**SelectedFigures;
			SelectedFigures = pManager->GetSelectedFigures();
			if (SelectedFigures == NULL)
			{
				
				pOut->setCrntPenColor(Clicked); //Clicked
				pOut->ClearDrawArea();
				return;

			}
			else
			{
				int i = 0;
				while (SelectedFigures[i] != NULL)
				{
					SelectedFigures[i]->ChngDrawClr(Clicked);
					SelectedFigures[i]->SetSelected(false);
					i++;
				}
				 pOut->ClearDrawArea();
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Color has been changed, click anywhere to continue");
				 pIn->GetPointClicked(P1.x,P1.y);
				  i=0;
				 while (SelectedFigures[i] != NULL)
				{
					SelectedFigures[i]->SetSelected(true);
					i++;
				}

			}


		 pOut->ClearDrawArea();
		// pOut->ClearStatusBar();
		}
	
	}   

	else
	{
		 pOut->ClearDrawArea();
		 pOut->PrintMessage("Invalid Point ,Please Choose another action");
		 return;	
	}

			 
}
void ChangeDrawColor::Execute()
{


	Output*pOut = pManager->GetOutput();
	pOut->DrawDropMenu(DM_CHANGEDRAWCOLOR);
	ReadActionParameters();


}