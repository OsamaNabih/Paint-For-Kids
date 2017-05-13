#include"ChangeFillColor.h"
#include "../Figures/CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillColor::ChangeFillColor(ApplicationManager *pApp) :Action(pApp)
{}
void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose your desired Fill Color");
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
			pOut->ClearDrawArea();
			return;	
		}
		CFigure**SelectedFigures;
		SelectedFigures = pManager->GetSelectedFigures();
		if (SelectedFigures == NULL)
		{
			pOut->setCrntFillColor(Clicked); //Clicked to be implemented
			pOut->ClearDrawArea();
			return;
		}
		else
		{
			int i = 0;
			while (SelectedFigures[i] != NULL)
			{
				SelectedFigures[i]->ChngFillClr(Clicked);
				i++;		
			}
		}      
	}
	else
	{
		 pOut->PrintMessage("Invalid Point ,Please Choose another action");
		 pOut->ClearDrawArea();
		 return;	
	}
	 pOut->ClearDrawArea();
}
void ChangeFillColor::Execute()
{


	Output*pOut = pManager->GetOutput();
	pOut->DrawDropMenu(DM_CHANGEDRAWCOLOR);
	ReadActionParameters();


}