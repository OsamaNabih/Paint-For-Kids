#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickAndHideAction :
	public Action
{
private:
	int CounterValid;
	int CounterInvalid;
	CFigure** PlayList;
public:
	PickAndHideAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	void PickByFigureTypeOrColor(int conditionType);
	void PickByFigureArea();
	virtual void Execute();
};

