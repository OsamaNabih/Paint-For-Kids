#include"FillMode.h"
#include "../Figures/CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
FillMode::FillMode(ApplicationManager *pApp) :Action(pApp)
{}
void FillMode::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->setFillMode(!(pOut->getFillMode()));
	string s = "Fill Mode: ";
	if (pOut->getFillMode())
		s += "On";
	else
		s += "Off";
	pOut->PrintMessage(s);
}
void FillMode::Execute()
{
	ReadActionParameters();
}