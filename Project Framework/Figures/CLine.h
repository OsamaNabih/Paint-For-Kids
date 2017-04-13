#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

