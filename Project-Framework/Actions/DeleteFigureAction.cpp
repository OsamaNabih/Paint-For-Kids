#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{
}


void DeleteAction::ReadActionParameters()
{
}


void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure** SelectedFigs = pManager->GetSelectedFigures();
	if (SelectedFigs == NULL)
		return;
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
}