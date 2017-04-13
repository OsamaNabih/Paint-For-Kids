#include "CCircle.h"



CCircle::CCircle(Point P1, double r, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = r;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected);
}