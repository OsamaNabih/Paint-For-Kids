#pragma once
#include "..\Actions\Action.h"
class DrawModeAction :
	public Action
{
public:
	DrawModeAction(ApplicationManager * pApp);
	~DrawModeAction();
	virtual void ReadActionParameters();
	virtual void Execute();
};

