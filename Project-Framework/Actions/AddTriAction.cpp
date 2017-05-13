#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!isValid(P1))
	{
		P1.x=0;
		P1.y=0;
		P2.x=0;
		P2.y=0;
		P3.x=0;
		P3.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Triangle: Click at second corner");

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
		P3.x=0;
		P3.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	while ((P1.x == P2.x && P1.x == P3.x && P2.x == P3.x) || (P1.y == P2.y && P1.y == P3.y && P2.y == P3.y))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another point");
		pIn->GetPointClicked(P3.x, P3.y);
	}
	if (!isValid(P3))
	{
		P1.x=0;
		P1.y=0;
		P2.x=0;
		P2.y=0;
		P3.x=0;
		P3.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}


	TriGfxInfo.isFilled = pOut->getFillMode();	//default is not filled
									//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	CTriangle *R;
	//Create a Triangle with the parameters read from the user
	if(P1.x != 0 && P1.y != 0 && P2.x != 0 && P2.y != 0 && P3.x != 0 && P3.y != 0)
	R = new CTriangle(P1, P2, P3, TriGfxInfo);
	else 
		return;
	//Add the Triangle to the list of figures
	pManager->AddFigure(R);
}
