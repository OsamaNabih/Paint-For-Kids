#include"SaveAction.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SaveAction::SaveAction(ApplicationManager *pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter The File Name");
	string FileName=pIn->GetSrting(pOut);
	ofstream SavedFile("Graphs/"+FileName+".txt",ios::out);
	SavedFile<<(int)UI.DrawColor.ucRed<<" "<< (int)UI.DrawColor.ucGreen<<" "
		<< (int)UI.DrawColor.ucBlue<<" "<< (int)UI.FillColor.ucRed<<" "
		<< (int)UI.FillColor.ucGreen<<" "<< (int)UI.FillColor.ucBlue<<" "
		<< (int)UI.BkGrndColor.ucRed<<" "<< (int)UI.BkGrndColor.ucGreen<<" "
		<< (int)UI.BkGrndColor.ucBlue<<endl;
	pManager->SaveAll(SavedFile);
}
void SaveAction::Execute()
{
	ReadActionParameters();
}