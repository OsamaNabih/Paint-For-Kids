#pragma once
#include "Action.h"
class PasteAction :
	public Action
{
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

