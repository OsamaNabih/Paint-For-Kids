#pragma once
#include "Action.h"
class FillMode :public Action
{
public:
	FillMode(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

