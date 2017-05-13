#pragma once
#include "..\Actions\Action.h"
class PlayModeAction :
	public Action
{
public:
	PlayModeAction(ApplicationManager * pApp);
	~PlayModeAction();
	virtual void ReadActionParameters();
	virtual void Execute();
};