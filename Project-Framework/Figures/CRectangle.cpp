#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID = NextID++;
	Length = abs(P2.x - P1.x);
	Width = abs(P2.y - P1.y);
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsPointHere(Point PClicked) const
{
	if (PClicked.y > min(Corner1.y, Corner2.y) && (PClicked.y < max(Corner1.y, Corner2.y)))
	{
		if (PClicked.x > min(Corner1.x, Corner2.x) && PClicked.x < max(Corner1.x, Corner2.x))
			return true;
	}
	return false;
}

float CRectangle::CalculateArea() const
{
	return Length * Width;
}

 void CRectangle::PrintInfo(Output* pOut) const
{
	 string OutMsg = "Selected Figure: Rectangle, ID = ";
	 OutMsg += to_string(ID);
	 OutMsg += ", Length = ";
	 OutMsg += to_string((int)Length);
	 OutMsg += ", Width = ";
	 OutMsg += to_string((int)Width);
	 OutMsg += ", Area = ";
	 OutMsg += to_string((int)CalculateArea());
	 pOut->PrintMessage(OutMsg);
}

 CFigure* CRectangle::CopyFigWithDefaultConstructor()
 {
	 return new CRectangle(Corner1, Corner2, FigGfxInfo);
 }

 CFigure* CRectangle::CopyFigWithCopyConstructor()
 {
	 return new CRectangle(*this);
 }

 Point CRectangle::CalculateMaxCoordinates() const
 {
	 Point Max;
	 Max.x = max(Corner1.x, Corner2.x);
	 Max.y = max(Corner1.y, Corner2.y);
	 return Max;
 }

 Point CRectangle::CalculateMinCoordinates() const
 {
	 Point Min;
	 Min.x = min(Corner1.x, Corner2.x);
	 Min.y = min(Corner1.y, Corner2.y);
	 return Min;
 }

void CRectangle::MoveFig(Point AxesTranslation)
 {
	Corner1.x += AxesTranslation.x;
	Corner1.y += AxesTranslation.y;
	Corner2.x += AxesTranslation.x;
	Corner2.y += AxesTranslation.y;
 }

bool CRectangle::Resize(float Factor)
{
	float MidX = (Corner1.x + Corner2.x) / 2.0;
	float MidY = (Corner1.y + Corner2.y) / 2.0;
	Point ResizedCorner1, ResizedCorner2;
	ResizedCorner1 = Corner1;
	ResizedCorner2 = Corner2;
	max(ResizedCorner1.x, ResizedCorner2.x) = MidX + (Length / 2.0 * sqrt(Factor));
	min(ResizedCorner1.x, ResizedCorner2.x) = MidX - (Length / 2.0 * sqrt(Factor));
	max(ResizedCorner1.y, ResizedCorner2.y) = MidY + (Width / 2.0 * sqrt(Factor));
	min(ResizedCorner1.y, ResizedCorner2.y) = MidY - (Width / 2.0 * sqrt(Factor));
	if (!isValid(ResizedCorner1) || !isValid(ResizedCorner2))
		return false;
	Corner1 = ResizedCorner1;
	Corner2 = ResizedCorner2;
	//Length = abs(Corner2.x - Corner1.x);
	//Width = abs(Corner2.y - Corner1.y);
	Length *= sqrt(Factor);
	Width *= sqrt(Factor);
	return true;
}

void CRectangle::WestSideTillWeDie()
{
	Corner1.x /= 2;
	Corner2.x /= 2;
}

void CRectangle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.isFilled)
	{
		OutFile << "RECT" << " FILLED " << ID << " " << Corner1.x << " " << Corner1.y << " "
			<< Corner2.x << " " << Corner2.y << " " << (int)FigGfxInfo.DrawClr.ucRed
			<< " " << (int)FigGfxInfo.DrawClr.ucGreen << " " << (int)FigGfxInfo.DrawClr.ucBlue
			<< " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen
			<< " " << (int)FigGfxInfo.FillClr.ucBlue << " " << FigGfxInfo.BorderWdth << endl;
	}
	else
	{
		OutFile << "RECT" << " NO_FILL " << ID << " " << Corner1.x << " " << Corner1.y << " "
			<< Corner2.x << " " << Corner2.y << " " << (int)FigGfxInfo.DrawClr.ucRed
			<< " " << (int)FigGfxInfo.DrawClr.ucGreen << " " << (int)FigGfxInfo.DrawClr.ucBlue
			<< " " << FigGfxInfo.BorderWdth << endl;
	}
}

void CRectangle::Load(ifstream & Loadfile)
{
	int Red, Green, Blue, Number;
	string Type;
	Point P1;
	Point P2;
	Loadfile >> Type;
	Loadfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> Red >> Green >> Blue;
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
	Length = abs(P2.x - P1.x);
	Width = abs(P2.y - P1.y);
	Loadfile >> FigGfxInfo.BorderWdth;
	return;
}
bool CRectangle::isFigureType(CFigure * checked)
{
	if (dynamic_cast<CRectangle*>(checked) != NULL)
		return true;
	else
		return false;
}
int CRectangle::getDimensionValue()
{
	return Length*Width;
}

CRectangle::~CRectangle()
{
}