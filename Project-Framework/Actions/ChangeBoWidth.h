#pragma once
#include"Action.h"
class ChangeBoWidth:public Action
{
	Point P1;
public:
	ChangeBoWidth(ApplicationManager *pApp);
	
	virtual void ReadActionParameters();


	virtual void Execute();


};
