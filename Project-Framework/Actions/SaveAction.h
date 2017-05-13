#pragma once
#include "Action.h"
class SaveAction :public Action
{
public:
	SaveAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

