#pragma once
#include "Action.h"
class ChangeFillColor :public Action
{
	Point P1;
public:
	ChangeFillColor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
