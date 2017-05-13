#pragma once
#include "Action.h"
class MoveAction :
	public Action
{
public:
	MoveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

