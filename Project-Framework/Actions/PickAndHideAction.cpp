#include "PickAndHideAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


PickAndHideAction::PickAndHideAction(ApplicationManager * pApp) :Action(pApp)
{
	CounterInvalid=0;
	CounterValid = 0;
	PlayList = pApp->CopyFigList();
}


void PickAndHideAction::ReadActionParameters()
{
	return;
}
void PickAndHideAction::PickByFigureTypeOrColor(int conditionType)
{
	if (PlayList == NULL || PlayList[0] == NULL)
		return;
	bool condition;
	Point P;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int counter = 0;
	bool foundFigure = false;
	bool foundFigures = false;
	pOut->PrintMessage("Choose a shape to start playing!");
	pIn->GetPointClicked(P.x, P.y);
	CFigure* Clicked = pManager->GetFigure(P.x, P.y);
	if (Clicked != NULL)
	{
		while (1)
		{
			switch (conditionType)
			{
			case 1:
				pOut->PrintMessage("Choose the same type");
				break;
			case 2:
				pOut->PrintMessage("Choose the same color");
				break;
			case 3:
				pOut->PrintMessage("Choose the same color and type");
				break;
			}
			pIn->GetPointClicked(P.x, P.y);
			while (PlayList[counter] != NULL)
			{
				switch (conditionType)
				{
				case 1:
					condition = PlayList[counter]->isFigureType(Clicked);
					break;
				case 2:
					condition = PlayList[counter]->GetColor() == Clicked->GetColor();
					break;
				case 3:
					condition = PlayList[counter]->isFigureType(Clicked) && PlayList[counter]->GetColor() == Clicked->GetColor();
					break;
				}
				if (condition)
				{
					foundFigures = true;
					if (PlayList[counter]->IsPointHere(P))
					{

						delete PlayList[counter];
						PlayList[counter] = NULL;
						int i = counter;
						foundFigure = true;
						while (PlayList[i + 1] != NULL)
						{
							PlayList[i] = PlayList[i + 1];
							i++;
						}
						PlayList[i] = NULL;
					}

				}
				counter++;
			}

			if (foundFigure && foundFigures)
				CounterValid++;
			else if (!foundFigure && foundFigures)
				CounterInvalid++;
			else
				break;
			foundFigures = false;
			foundFigure = false;
			pOut->ClearDrawArea();
			counter = 0;
			while (PlayList[counter] != NULL)
				PlayList[counter++]->Draw(pOut);
			counter = 0;
		}
	}
}
void PickAndHideAction::PickByFigureArea()
{
	Point P;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Counter=1;
	int Max;
	bool Clicked=false;
	while(1)
	{
		if(PlayList == NULL || PlayList[0] == NULL)
			break;
	    pIn->GetPointClicked(P.x,P.y);
		Max=PlayList[0]->getDimensionValue();
			while(PlayList[Counter]!=NULL)
			{
				if(PlayList[Counter]->getDimensionValue()>Max)
					Max=PlayList[Counter]->getDimensionValue();
					Counter++;
			}
			Counter=0;
			while(PlayList[Counter]!=NULL)
			{
				if(PlayList[Counter]->IsPointHere(P) && PlayList[Counter]->getDimensionValue()==Max)
				{
					delete PlayList[Counter];
					PlayList[Counter] = NULL;
					int i = Counter;
					while(PlayList[i+1] != NULL)
					{
						PlayList[i] = PlayList[i+1];
						i++;
					}
					PlayList[i] = NULL;
					Clicked=true;
					break;
				}
				Counter++;
			}
			if(Clicked)
				CounterValid++;
			else
				CounterInvalid++;
			Clicked=false;
			pOut->ClearDrawArea();
			Counter = 0;
			while (PlayList[Counter] != NULL)
				PlayList[Counter++]->Draw(pOut);
			Counter = 0;
	}
}				
void PickAndHideAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->DrawDropMenu(DM_PickAndHide);
	Point P;
	int type=4;
	// DO THE PICKING HERE
	pOut->PrintMessage("PickAndHideMode: Activated!");
	pIn->GetPointClicked(P.x,P.y);
	if(P.x > ITM_ReSize * UI.MenuItemWidth  && P.x < (4 + ITM_ReSize) * UI.MenuItemWidth && P.y > UI.MenuItemWidth && P.y < 2 * UI.MenuItemWidth)
	{
		int Type =(P.x -ITM_ReSize*UI.MenuItemWidth)/UI.MenuItemWidth ;
		switch(Type) 
		{
			case 1:
				PickByFigureTypeOrColor(1);
				break;
			case 2:
				PickByFigureTypeOrColor(2);
				break;
			case 3:
				PickByFigureTypeOrColor(3);
				break;
			case 4 :
				PickByFigureArea();
				break;
		}
		
		pOut->ClearDrawArea();
    }
	else 
	{
		pOut->PrintMessage("Invalid Point");
		pOut->ClearDrawArea();
	}
}
