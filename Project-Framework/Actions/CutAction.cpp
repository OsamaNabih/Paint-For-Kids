#include "CutAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


CutAction::CutAction(ApplicationManager * pApp) :Action(pApp)
{
}


void CutAction::ReadActionParameters()
{
}


void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure** SelectedFigs = pManager->GetSelectedFigures();
	if (SelectedFigs == NULL)
		return;
	pManager->AddToClipBoard(SelectedFigs);
	int i = 0;
	while (SelectedFigs[i] != NULL)
	{
		pManager->DeleteFig(SelectedFigs[i]->GetId());
		delete SelectedFigs[i];
		SelectedFigs[i] = NULL;
		i++;
	}
	pOut->ClearDrawArea();
	delete SelectedFigs;
	pOut->PrintMessage("Selected figures have been cut successfully");
}