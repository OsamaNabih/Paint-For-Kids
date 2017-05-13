#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	float Area(Point X, Point Y, Point Z) const; //Utility function
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointHere(Point X) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* CopyFigWithDefaultConstructor();
	virtual CFigure* CopyFigWithCopyConstructor();
	virtual Point CalculateMaxCoordinates() const;
	virtual Point CalculateMinCoordinates() const;
	virtual void MoveFig(Point);
	virtual void WestSideTillWeDie();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream & Loadfile);
	virtual bool Resize(float Factor);
	virtual bool isFigureType(CFigure* checked);
	virtual int getDimensionValue();
	~CTriangle();
};