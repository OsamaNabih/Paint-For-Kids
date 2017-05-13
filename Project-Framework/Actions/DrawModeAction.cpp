#include "DrawModeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DrawModeAction::DrawModeAction(ApplicationManager * pApp) : Action(pApp)
{
}


DrawModeAction::~DrawModeAction()
{
}


void DrawModeAction::ReadActionParameters()
{
}
void DrawModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->setInterfaceMode(MODE_DRAW);
	pOut->CreateDrawToolBar();
	pOut->ClearDrawArea();
	pOut->PrintMessage("Draw Mode engaged!");
}


