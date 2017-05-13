#include "CFigure.h"
int CFigure::NextID = 1;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::ChngBoWidth(int x)
{
	FigGfxInfo.BorderWdth = (x + 1) * 3;
}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::GetId()
{
	return ID;
}


bool CFigure::isValid(Point P)
{
	if (P.x > UI.width || P.x < 0)
		return false;
	if (P.y >(UI.height - UI.StatusBarHeight) || P.y < UI.ToolBarHeight)
		return false;
	return true;
}

void CFigure::setNextID(int ID)
{
	NextID = ID;
}
color CFigure::GetColor()
{
	return FigGfxInfo.FillClr;

}

CFigure::~CFigure()
{
}