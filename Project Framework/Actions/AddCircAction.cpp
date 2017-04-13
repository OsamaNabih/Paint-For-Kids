#include "AddCircAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddCircAction::AddCircAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!isValid(P1))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Circle: Click to determine radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (!isValid(P2))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	CircGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//If the user attempts to draw a circle outside of the permitted area, display an error message
	//and we don't create the object
	//We must calculate the radius first in order to do that
	double r = sqrt(((P2.x - P1.x) * (P2.x - P1.x)) + ((P2.y - P1.y) * (P2.y - P1.y)));
	if ((P1.y - r) < UI.ToolBarHeight || (P1.y + r) > (UI.height - UI.StatusBarHeight) || (P1.x - r < 0) || (P1.x + r) > UI.width)
	{
		(pManager->GetOutput())->PrintMessage("Please choose Points inside drawing area");
		return;
	}


	//Create a rectangle with the parameters read from the user
	CCircle *R = new CCircle(P1, r, CircGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}

