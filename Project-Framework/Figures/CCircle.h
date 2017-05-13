#pragma once
#include "CFigure.h"
class CCircle :
	public CFigure
{
	Point Center;
	double Radius;
public:
	CCircle(Point P1, double r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointHere(Point) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* CopyFigWithDefaultConstructor();
	virtual CFigure* CopyFigWithCopyConstructor();
	float CalculateArea() const;
	virtual Point CalculateMaxCoordinates() const;
	virtual Point CalculateMinCoordinates() const;
	virtual void MoveFig(Point);
	virtual void WestSideTillWeDie();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream & Loadfile);
	virtual bool Resize(float Factor);
	virtual bool isFigureType(CFigure* checked);
	virtual int getDimensionValue();

	~CCircle();
};

