#include "ChangeBoWidth.h"
#include "../Figures/CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ChangeBoWidth::ChangeBoWidth(ApplicationManager * pApp):Action(pApp)
{}
void ChangeBoWidth:: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose your desired width");

	pIn->GetPointClicked(P1.x,P1.y);

	if (!isValid(P1) || ((ITM_BorderWidth-1)*UI.MenuItemWidth > P1.x && P1.x > ITM_BorderWidth*UI.MenuItemWidth) || P1.y > (2.5*UI.MenuItemWidth))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		pOut->ClearDrawArea();
		//pManager->UpdateInterface();
		return;
	}
 
		CFigure**SelectedFigures;
		int Thickness =(P1.y -UI.MenuItemWidth)/25 ;
		SelectedFigures =pManager->GetSelectedFigures();

	if (SelectedFigures==NULL)
      {
	    
	    switch(Thickness) 
	     {
		  case 0 :
		  {
			  pOut->setCrntPenWidth((Thickness + 1) * 3);
			  pOut->PrintMessage("Chosen Border Width: Small");
			  break;
		  }
	      case 1 :
		  {
			  pOut->setCrntPenWidth((Thickness + 1) * 3);
			  pOut->PrintMessage("Chosen Border Width: Medium");
			  break;
		  }
		  case 2 :
		  {
			  pOut->setCrntPenWidth((Thickness + 1) * 3);
			  pOut->PrintMessage("Chosen Border Width: Large");
			  break;
		  }
		 }
	   //pManager->UpdateInterface();
		pOut->ClearDrawArea();
		return;
	 }
	else 
	{
		int i=0;
		while(SelectedFigures[i]!=NULL)
		{
			SelectedFigures[i]->ChngBoWidth(Thickness);
			i++;
		}

		delete[]SelectedFigures;
	}
	pOut->ClearDrawArea();

}
void ChangeBoWidth::Execute()
{
	Output*pOut=pManager->GetOutput();
	pOut->DrawDropMenu(DM_CHANGEBORDERWIDTH);
	ReadActionParameters();


     
}


