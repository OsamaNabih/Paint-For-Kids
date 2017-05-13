#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!isValid(P1))
	{
		P1.x=0;
		P1.y=0;
		P2.x=0;
		P2.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	
	while (P2.x == P1.x || P2.y == P1.y)
	{
			(pManager->GetOutput())->PrintMessage("Invalid point, please select another point");
			pIn->GetPointClicked(P2.x, P2.y);
	}
	if (!isValid(P2))
	{
		P1.x=0;
		P1.y=0;
		P2.x=0;
		P2.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	RectGfxInfo.isFilled = pOut->getFillMode();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}


//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	CRectangle *R;
	//Create a rectangle with the parameters read from the user
	if(P1.x != 0 && P1.y != 0 && P2.x != 0 && P2.y != 0)
		R = new CRectangle(P1, P2, RectGfxInfo);
	else 
		return;
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
