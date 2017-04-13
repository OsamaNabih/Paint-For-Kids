#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLin(Vertix1, Vertix2, FigGfxInfo, Selected);
}