#include "CopyAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp)
{
}


void CopyAction::ReadActionParameters()
{
}


void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure** SelectedFigs = pManager->GetSelectedFigures();
	if (SelectedFigs == NULL)
		return;
	pManager->AddToClipBoard(SelectedFigs);
	delete SelectedFigs;
	pOut->PrintMessage("Selected figures added to clipboard");
}