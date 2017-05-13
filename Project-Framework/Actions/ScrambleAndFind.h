#pragma once
#include "..\Actions\Action.h"
#include "../Figures/CFigure.h"
class ScrambleAndFind :
	public Action
{
private:
	void DrawList(CFigure** List, int Count);
public:
	ScrambleAndFind(ApplicationManager * pApp);
	~ScrambleAndFind();
	virtual void ReadActionParameters();
	virtual void Execute();
};

