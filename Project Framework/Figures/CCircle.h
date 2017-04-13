#pragma once
#include "C:\D\PDFS\College\1st year - 2nd term\Programming techniques\Project\CMP103-Project-S2017 - std\Project Framework\Figures\CFigure.h"
class CCircle :
	public CFigure
{
private:
	Point Center;
	double Radius;
public:
	CCircle(Point P1, double r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

