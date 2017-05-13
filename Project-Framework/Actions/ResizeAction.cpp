#include "ResizeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{
}


void ResizeAction::ReadActionParameters()
{

}


void ResizeAction::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->DrawDropMenu(DM_RESIZE);
	pOut->PrintMessage("Choose your desired factor");
	Point P1;
	pIn->GetPointClicked(P1.x,P1.y);
	float factor;
	if(P1.x > ITM_ReSize * UI.MenuItemWidth  && P1.x < (4 + ITM_ReSize) * UI.MenuItemWidth && P1.y > UI.MenuItemWidth && P1.y < 2 * UI.MenuItemWidth)
	{
		int Index =(P1.x -ITM_ReSize*UI.MenuItemWidth)/UI.MenuItemWidth ;
		switch(Index) 
		{
		  case 0 :
			  factor=0.25;
			  break;
		  case 1 :
			  factor = 0.5;
				  break;
		  case 2 :
			  factor =2;
			  break;
		  case 3 :
			  factor =4;
			  break;
		}
		pManager->ResizeAll(factor);
		pOut->ClearDrawArea();
    }
	else 
	{
		pOut->PrintMessage("Invalid Point");
				pOut->ClearDrawArea();
	}
}