#pragma once
#include "Action.h"
class LoadAction :public Action
{
public:
	LoadAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

