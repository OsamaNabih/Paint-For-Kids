#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
	Point P1;
	Point P2;
	float Length;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	float CalculateSlope() const;
	virtual void Draw(Output* pOut) const;
	virtual void WestSideTillWeDie();
	virtual bool IsPointHere(Point) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* CopyFigWithDefaultConstructor();
	virtual CFigure* CopyFigWithCopyConstructor();
	virtual Point CalculateMaxCoordinates() const;
	virtual Point CalculateMinCoordinates() const;
	virtual void MoveFig(Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream & Loadfile);
	virtual bool Resize(float Factor);
	virtual bool isFigureType(CFigure* checked);
	virtual int getDimensionValue();
	virtual ~CLine();
};

