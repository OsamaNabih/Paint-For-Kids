#pragma once
#include"Action.h"
class ChangeDrawColor :public Action
{
	Point P1;
public:
	ChangeDrawColor(ApplicationManager *pApp);

	virtual void ReadActionParameters();


	virtual void Execute();


};
