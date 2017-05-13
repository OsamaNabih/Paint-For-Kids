#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
	Point Corner1;	
	Point Corner2;
	float Length;
	float Width;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	float CalculateArea() const;
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointHere(Point X) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual CFigure* CopyFigWithDefaultConstructor();
	virtual CFigure* CopyFigWithCopyConstructor();
	virtual Point CalculateMaxCoordinates() const;
	virtual Point CalculateMinCoordinates() const;
	virtual void MoveFig(Point);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream & Loadfile);
	virtual void WestSideTillWeDie();
	virtual bool Resize(float Factor);
	virtual bool isFigureType(CFigure* checked);
	virtual int getDimensionValue();
	~CRectangle();
};
#endif