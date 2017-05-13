#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"
class AddLineAction :public Action
{
private:
	Point P1, P2; //Line Vertices
	GfxInfo LinGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads Lines parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();
};

#endif;