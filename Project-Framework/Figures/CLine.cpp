#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	this->P1 = P1;
	this->P2 = P2;
	ID = NextID++;
	Length = sqrt(((P2.x - P1.x) * (P2.x - P1.x)) + ((P2.y - P1.y) * (P2.y - P1.y)));
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLin(P1, P2, FigGfxInfo, Selected);
}

bool CLine::IsPointHere(Point PointClickedByUser) const
{
	float Xs = (float)(PointClickedByUser.x - P1.x) / (P2.x - P1.x);
	float Ys = (float)(PointClickedByUser.y - P1.y) / (P2.y - P1.y);
	if(abs(Xs-Ys) >= 0 && abs(Xs-Ys) < 0.015 + ((1 + UI.PenWidth) / Length))
		return true;
	return false;
}

float CLine::CalculateSlope() const
{
	return ((float(P2.y) - P1.y) / (P2.x - P1.x));
}



void CLine::PrintInfo(Output* pOut) const
{
	string OutMsg = "Selected Figure: Line, ID = ";
	OutMsg += to_string(ID);
	OutMsg += ", Start Point: (";
	OutMsg += to_string(P1.x);
	OutMsg += ",";
	OutMsg += to_string(P1.y);
	OutMsg += "), End Point: (";
	OutMsg += to_string(P2.x);
	OutMsg += ",";
	OutMsg += to_string(P2.y);
	OutMsg += "), Slope = ";
	OutMsg += to_string(CalculateSlope());
	OutMsg += " Length = " + to_string(Length);
	pOut->PrintMessage(OutMsg);
}

CFigure* CLine::CopyFigWithDefaultConstructor()
{
	return new CLine(P1, P2, FigGfxInfo);
}

CFigure* CLine::CopyFigWithCopyConstructor()
{
	return new CLine(*this);
}

Point CLine::CalculateMaxCoordinates() const
{
	Point Max;
	Max.x = max(P1.x, P2.x);
	Max.y = max(P1.y, P1.y);
	return Max;
}


Point CLine::CalculateMinCoordinates() const
{
	Point Min;
	Min.x = min(P1.x, P2.x);
	Min.y = min(P1.y, P2.y);
	return Min;
}

void CLine::MoveFig(Point AxesTranslation)
{
	P1.x += AxesTranslation.x;
	P1.y += AxesTranslation.y;
	P2.x += AxesTranslation.x;
	P2.y += AxesTranslation.y;
}

void CLine::Save(ofstream& OutFile)
{
	OutFile << "LINE   " << ID << " " << P1.x << " " << P1.y << " "
		<< P2.x << " " << P2.y << " " << (int)FigGfxInfo.DrawClr.ucRed
		<< " " << (int)FigGfxInfo.DrawClr.ucGreen << " " << (int)FigGfxInfo.DrawClr.ucBlue
		//<< " " << (int)FigGfxInfo.FillClr.ucRed << " "
		//<< (int)FigGfxInfo.FillClr.ucGreen << " " << (int)FigGfxInfo.FillClr.ucBlue << " " 
		<< FigGfxInfo.BorderWdth << " " << FigGfxInfo.isFilled << endl;
}

bool CLine::Resize(float Factor)
{
	Point MPoint, ResizedP1, ResizedP2;
	MPoint.x = (P1.x + P2.x) / 2;
	MPoint.y = (P1.y + P2.y) / 2;
	ResizedP1.x = MPoint.x + ((P1.x - MPoint.x) * (Factor));
	ResizedP1.y = MPoint.y + ((P1.y - MPoint.y) * (Factor));
	ResizedP2.x = MPoint.x + ((P2.x - MPoint.x) * (Factor));
	ResizedP2.y = MPoint.y + ((P2.y - MPoint.y) * (Factor));
	if (!isValid(ResizedP1) || !isValid(ResizedP2))
		return false;
	P1 = ResizedP1;
	P2 = ResizedP2;
	return true;
}

void CLine::WestSideTillWeDie()
{
	P1.x /= 2;
	P2.x /= 2;
}


void CLine::Load(ifstream & Loadfile)
{
	int Red, Green, Blue, Number;
	string Type;
	Point P1;
	Point P2;
	Loadfile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> Red >> Green >> Blue;
	if (NextID <= ID)
		NextID = ID + 1;
	color Dummy = color(Red, Green, Blue);
	FigGfxInfo.DrawClr = Dummy;
	UI.FillMode = false;
	UI.FillColor = Dummy;
	this->P1 = P1;
	this->P2 = P2;
	Length = sqrt(((P2.x - P1.x) * (P2.x - P1.x)) + ((P2.y - P1.y) * (P2.y - P1.y)));
	Loadfile >> FigGfxInfo.BorderWdth;
	return;
}
bool CLine::isFigureType(CFigure * checked)
{
	if (dynamic_cast<CLine*>(checked) != NULL)
		return true;
	else
		return false;
}
int CLine::getDimensionValue()
{
	return Length;
}

CLine::~CLine()
{
}
