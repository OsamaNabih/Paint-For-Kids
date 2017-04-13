#ifndef ACTION_H
#define ACTION_H

#include "..\DEFS.h"
#include "C:\D\PDFS\College\1st year - 2nd term\Programming techniques\Project\CMP103-Project-S2017 - std\Project Framework\GUI\UI_Info.h"
class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

	//To undo this action (code depends on action type)
	//virtual void Undo()=0;

	//To redo this action (code depends on action type)
	//virtual void Redo()=0;
protected: bool isValid(Point P) //utility function to check if point is inside drawing area
{
	if (P.y > (UI.height - UI.StatusBarHeight) || P.y < UI.ToolBarHeight)
		return false;
	return true;
}
};

#endif