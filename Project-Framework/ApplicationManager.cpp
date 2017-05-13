#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddlineAction.h"
#include "Actions\SelectAction.h"
#include "Actions\ChangeBoWidth.h"
#include "Actions\ChangeDrawColor.h"
#include "Actions\ChangeFillColor.h"
#include "Actions\FillMode.h"
#include "Actions\ChangeBackGround.h"
#include "Actions\CopyAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\CutAction.h"
#include "Actions\MoveAction.h"
#include "Actions\SaveAction.h"
#include "Actions\PasteAction.h"
#include "Actions\ResizeAction.h"
#include "ACtions\LoadAction.h"
#include "Actions\PlayModeAction.h"
#include "Actions\PickAndHideAction.h"
#include "Actions\ScrambleAndFind.h"
#include "Actions\DrawModeAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		FigListOfCopy[i] = NULL;
	}
			
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
CFigure** ApplicationManager::GetSelectedFigures() const
{
	int Counters = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			Counters++;
	}
	Counters++;
	if (Counters == 1)
		return NULL;
	CFigure** GetIt = new CFigure*[Counters];
	Counters = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			GetIt[Counters] = FigList[i];
			Counters++;
		}
	}
	GetIt[Counters] = NULL;
	return GetIt;
}
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case SELECT_FIGURE:
			pAct = new SelectAction(this);
			break;
		case CHANGE_BWIDTH:
			pAct = new ChangeBoWidth(this);
			break;
		case CHNG_BORD_CLR:
			pAct = new ChangeDrawColor(this);
			break;
		case CHNG_FILL_CLR:
			pAct = new ChangeFillColor(this);
			break;
		case FILL_MODE:
			pAct = new FillMode(this);
			break;
		case CHNG_BK_CLR:
			pAct = new ChangeBackGround(this);
			break;
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case COPY:
			pAct = new  CopyAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case RESIZE:
			pAct = new ResizeAction(this);
			break;
		case TO_PLAY:
			pAct = new PlayModeAction(this);
			break;
		case PCK_HIDE:
			pAct = new PickAndHideAction(this);
			break;
		case SCM_FIND:
			pAct = new ScrambleAndFind(this);
			break;
		case TO_DRAW:
			pAct = new DrawModeAction(this);
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::DeleteFig(int ID)
{
	int index;
	for (int i = 0; i < FigCount; i++)
	{
		if (ID == FigList[i]->GetId())
		{
			FigList[i] = NULL;
			index = i;
			break;
		}
	}
	for (int i = index; i < FigCount; i++)
	{
		FigList[i] = FigList[i + 1];
	}
	FigCount--;
}
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	///Add your code here to search for a figure given a point x,y	
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point P;
	P.x = x;
	P.y = y;
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->IsPointHere(P))
		{
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	int i = 0;
	while (FigListOfCopy[i] != NULL)
	{
		delete FigListOfCopy[i];
		i++;
	}
}

void ApplicationManager::AddToClipBoard(CFigure** selected)
{
	int i = 0;
	while (FigListOfCopy[i] != NULL)
	{
		delete FigListOfCopy[i];
		FigListOfCopy[i] = NULL;
		i++;
	}
	i = 0;
	while (selected[i] != NULL)
	{
		FigListOfCopy[i] = selected[i]->CopyFigWithCopyConstructor();
		i++;
	}
}

CFigure** ApplicationManager::GetCopied()
{
	return FigListOfCopy;
}

void ApplicationManager::SaveAll(ofstream& SavedFile)
{
	SavedFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(SavedFile);
	}
}

void ApplicationManager::AddFromClipBoard()
{
	int i = 0;
	while (FigListOfCopy[i] != NULL)
	{
		AddFigure(FigListOfCopy[i]->CopyFigWithDefaultConstructor());
		i++;
	}
}

void ApplicationManager::SetID(int id)
{
	FigList[FigCount - 1]->SetID(id);
}

void ApplicationManager::DeleteALLFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}

void ApplicationManager::ResizeAll(float Factor)
{
	CFigure** Selected = GetSelectedFigures();
	int i = 0;
	bool Possible = true;
	if (Selected == NULL)
		return;
	while (Selected[i] != NULL)
	{
		Possible = Selected[i]->Resize(Factor);
		if (!Possible)
			break;
		i++;
	}
	if (!Possible)
	{
		if (i == 0)
			return;
		i--;
		while (i >= 0)
		{
			Selected[i]->Resize(1 / Factor);
			i--;
		}
	}
}

void ApplicationManager::LoadFile(ifstream & Loadfile)
{
	pOut->ClearDrawArea();
	if (!Loadfile.eof())
	{
		FigList[FigCount - 1]->Load(Loadfile);
	}
	return;
}

void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}

CFigure** ApplicationManager::CopyFigList()
{
	if (FigCount == 0)
		return NULL;
	CFigure** Copied = new CFigure*[FigCount];
	for (int i = 0; i < FigCount; i++)
	{
		Copied[i] = FigList[i]->CopyFigWithCopyConstructor();
	}
	Copied[FigCount] = NULL;
	return Copied;
}