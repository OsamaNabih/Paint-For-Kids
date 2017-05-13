#pragma once
#include "Action.h"
class ChangeBackGround :public Action
{
	Point P1;
public:
	ChangeBackGround(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

