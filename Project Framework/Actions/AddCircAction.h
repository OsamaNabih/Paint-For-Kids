#pragma once
#include "Action.h"
class AddCircAction :
	public Action
{
private:
	Point P1, P2; //Circangle Corners
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

