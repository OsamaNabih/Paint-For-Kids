#pragma once
#include "Action.h"
class CutAction :
	public Action
{
public:
	CutAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};

