#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID = NextID++;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrian(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
bool CTriangle::IsPointHere(Point X) const
{
	float AreaTriangle = Area(Corner1, Corner2, Corner3);
	float AreaTrianglePoint1 = Area(X, Corner2, Corner3);
	float AreaTrianglePoint2 = Area(Corner1, X, Corner3);
	float AreaTrianglePoint3 = Area(Corner1, Corner2, X);
	if ((AreaTriangle - (AreaTrianglePoint1 + AreaTrianglePoint2 + AreaTrianglePoint3)) < 1 && (AreaTriangle - (AreaTrianglePoint1 + AreaTrianglePoint2 + AreaTrianglePoint3)) >= 0)
		return true;
	else
		return false;
}

float CTriangle::Area(Point X,Point Y,Point Z) const
{
	return abs(((X.x*(Y.y - Z.y) + Y.x*(Z.y - X.y) + Z.x*(X.y - Y.y)) / 2.0));
}

void CTriangle::PrintInfo(Output* pOut) const
{
	string OutMsg = "Selected Figure: Triangle, ID = ";
	OutMsg += to_string(ID);
	OutMsg += ", Area = ";
	OutMsg += to_string(Area(Corner1, Corner2, Corner3));
	pOut->PrintMessage(OutMsg);
}

CFigure* CTriangle::CopyFigWithDefaultConstructor()
{
	return new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
}

CFigure* CTriangle::CopyFigWithCopyConstructor()
{
	return new CTriangle(*this);
}


Point CTriangle::CalculateMaxCoordinates() const
{
	Point Max;
	Max.x = max(Corner1.x, max(Corner2.x, Corner3.x));
	Max.y = max(Corner1.y, max(Corner2.y, Corner3.y));
	return Max;
}

Point CTriangle::CalculateMinCoordinates() const
{
	Point Min;
	Min.x = min(Corner1.x, min(Corner2.x, Corner3.x));
	Min.y = min(Corner1.y, min(Corner2.y, Corner3.y));
	return Min;
}

void CTriangle::MoveFig(Point AxesTranslation)
{
	Corner1.x += AxesTranslation.x;
	Corner1.y += AxesTranslation.y;
	Corner2.x += AxesTranslation.x;
	Corner2.y += AxesTranslation.y;
	Corner3.x += AxesTranslation.x;
	Corner3.y += AxesTranslation.y;
}

bool CTriangle::Resize(float Factor)
{
	return true;
}

void CTriangle::WestSideTillWeDie()
{
	Corner1.x /= 2;
	Corner2.x /= 2;
	Corner3.x /= 2;
}

void CTriangle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.isFilled)
	{
		OutFile << "TRIANG" << " FILLED " << ID << " " << Corner1.x << " " << Corner1.y
			<< " " << Corner2.x << " " << Corner2.y << " " << Corner3.x
			<< " " << Corner3.y << " " << (int)FigGfxInfo.DrawClr.ucRed
			<< " " << (int)FigGfxInfo.DrawClr.ucGreen << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " <<
			(int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen
			<< " " << (int)FigGfxInfo.FillClr.ucBlue << " " << FigGfxInfo.BorderWdth << endl;
	}
	else
	{
		OutFile << "TRIANG" << " NO_FILL " << ID << " " << Corner1.x << " " << Corner1.y
			<< " " << Corner2.x << " " << Corner2.y << " " << Corner3.x
			<< " " << Corner3.y << " " << (int)FigGfxInfo.DrawClr.ucRed
			<< " " << (int)FigGfxInfo.DrawClr.ucGreen << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << FigGfxInfo.BorderWdth << endl;
	}
}

void CTriangle::Load(ifstream & Loadfile)
{
	int Red, Green, Blue, Number;
	string Type;
	Point P1;
	Point P2;
	Point P3;
	Loadfile >> Type;
	Loadfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> Red >> Green >> Blue;
	if (NextID <= ID)
		NextID = ID + 1;
	color Dummy = color(Red, Green, Blue);
	FigGfxInfo.DrawClr = Dummy;
	if (Type == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = Dummy;
	}
	else
	{
		Loadfile >> Red >> Green >> Blue;
		Dummy = color(Red, Green, Blue);
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = Dummy;

	}
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Loadfile >> FigGfxInfo.BorderWdth;
	return;
}

bool CTriangle::isFigureType(CFigure * checked)
{
	if (dynamic_cast<CTriangle*>(checked) != NULL)
		return true;
	else
		return false;
}
int CTriangle::getDimensionValue()
{
	return Area(Corner1, Corner2, Corner3);
}

CTriangle::~CTriangle()
{
}