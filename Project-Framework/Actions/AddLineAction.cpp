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
		P1.x=0;
		P1.y=0;
		P2.x=0;
		P2.y=0;
		(pManager->GetOutput())->PrintMessage("Invalid point, please select another action");
		return;
	}

	pOut->PrintMessage("New Line: Click at the second point");

	//Read 2nd Vertix and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	while(P1.x == P2.x && P2.y == P2.y)
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

	LinGfxInfo.isFilled = pOut->getFillMode();	//default is not filled
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


	CLine *R;
	//Create a Line with the parameters read from the user
	if(P1.x != 0 && P1.y != 0 && P2.x != 0 && P2.y != 0)
	R = new CLine(P1, P2, LinGfxInfo);
	else 
		return;
	//Add the Line to the list of figures
	pManager->AddFigure(R);
}



