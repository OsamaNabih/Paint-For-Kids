#pragma once
#include "Action.h"
class CopyAction :
	public Action
{
public:
	CopyAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
};

