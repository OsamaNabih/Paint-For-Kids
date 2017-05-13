#include "PlayModeAction.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PlayModeAction::PlayModeAction(ApplicationManager * pApp) :Action(pApp)
{
}


PlayModeAction::~PlayModeAction()
{
}

void PlayModeAction::ReadActionParameters()
{
}
void PlayModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->setInterfaceMode(MODE_PLAY);
	pOut->CreatePlayToolBar();
	pOut->ClearDrawArea();
	pManager->UnselectAll();
	pOut->PrintMessage("Play Mode engaged!");
}

