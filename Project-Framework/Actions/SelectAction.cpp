#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{
}


void SelectAction::ReadActionParameters()
{

}


void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string s1 = "Selection mode is on. ";
	string s2 = "Number of selected figures = ";
	string s3 = "";
	int x, y, SelectedFigNum, i;
	pOut->PrintMessage("Selection mode: enabled");
	SelectedFigNum = 0;
	CFigure** temp2 = pManager->GetSelectedFigures();
	i = 0;
	if (temp2 != NULL)
	{
		while (temp2[i] != NULL)
		{
			SelectedFigNum++;
			i++;
		}
		if (SelectedFigNum == 1)
			temp2[0]->PrintInfo(pOut);
		else if (SelectedFigNum > 1)
		{
			s3 = to_string(SelectedFigNum);
			pOut->PrintMessage(s1 + s2 + s3);
		}		
	}
	pIn->GetPointClicked(x, y);
	while ((x / UI.MenuItemWidth) != ITM_SFigure  || y > UI.ToolBarHeight)
	{
		CFigure* temp = pManager->GetFigure(x, y);
		if (temp == NULL)
		{
			pIn->GetPointClicked(x, y);
			continue;
		}
		if (temp->IsSelected())
		{
			temp->SetSelected(false);
			SelectedFigNum--;
			if (SelectedFigNum > 1)
			{
				s3 = to_string(SelectedFigNum);
				pOut->PrintMessage(s1 + s2 + s3);
			}
			else if (SelectedFigNum == 1)
				temp->PrintInfo(pOut);
			else if (SelectedFigNum == 0)
				pOut->PrintMessage(s1 + "No selected figures");
		}
		else
		{
			temp->SetSelected(true);
			SelectedFigNum++;
			if (SelectedFigNum == 1)
				temp->PrintInfo(pOut);
			else if (SelectedFigNum > 1)
			{
				s3 = to_string(SelectedFigNum);
				pOut->PrintMessage(s1 + s2 + s3);
			}
			else if (SelectedFigNum == 0)
			{
				pOut->PrintMessage(s1 + "No selected figures"); 
			}
		}
		pManager->UpdateInterface();
		if (SelectedFigNum == 1)
		{
			CFigure** temp2 = pManager->GetSelectedFigures();
			temp2[0]->PrintInfo(pOut);
		}
		pIn->GetPointClicked(x, y);
	}
	pOut->PrintMessage("Selection mode: disabled");
}