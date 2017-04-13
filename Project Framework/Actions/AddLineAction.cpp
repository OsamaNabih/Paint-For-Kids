#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at the first point");

	//Read 1st Vertix and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (!isValid(P1))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Line: Click at the second point");

	//Read 2nd Vertix and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (!isValid(P2))
	{
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	LinGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	LinGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LinGfxInfo.FillClr = pOut->getCrntFillColor();
	LinGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();



	//Create a Line with the parameters read from the user
	CLine *R = new CLine(P1, P2, LinGfxInfo);

	//Add the Line to the list of figures
	pManager->AddFigure(R);
}



