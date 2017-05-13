#include "CCircle.h"



CCircle::CCircle(Point P1, double r, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = r;
	ID = NextID++;
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pOut->DrawCir(Center, Radius, FigGfxInfo, Selected);
}

bool CCircle::IsPointHere(Point PointClickedByUser) const
{
	double DistanceBetweenPoints = sqrt(((PointClickedByUser.x - Center.x) * (PointClickedByUser.x - Center.x)) + ((PointClickedByUser.y - Center.y) * (PointClickedByUser.y - Center.y)));
	if (DistanceBetweenPoints <= Radius)
		return true;
	return false;
}

float CCircle::CalculateArea() const
{
	return 3.14 * Radius * Radius;
}

void CCircle::PrintInfo(Output* pOut) const
{
	string OutMsg = "Selected Figure: Circle, ID = ";
	OutMsg += to_string(ID);
	OutMsg += ", Center: (";
	OutMsg += to_string(Center.x);
	OutMsg += ",";
	OutMsg += to_string(Center.y);
	OutMsg += "), Radius = ";
	OutMsg += to_string(Radius);
	OutMsg += ", Area = ";
	OutMsg += to_string(CalculateArea());
	pOut->PrintMessage(OutMsg);
}

CFigure* CCircle::CopyFigWithDefaultConstructor()
{
	return new CCircle(Center, Radius, FigGfxInfo);
}

CFigure* CCircle::CopyFigWithCopyConstructor()
{
	return new CCircle(*this);
}

Point CCircle::CalculateMaxCoordinates() const
{
	Point Max;
	Max.x = Center.x + Radius;
	Max.y = Center.y + Radius;
	return Max;
}

Point CCircle::CalculateMinCoordinates() const
{
	Point Min;
	Min.x = Center.x - Radius;
	Min.y = Center.y - Radius;
	return Min;
}

void CCircle::MoveFig(Point AxesTranslation)
{
	Center.x += AxesTranslation.x;
	Center.y += AxesTranslation.y;
}

bool CCircle::Resize(float Factor)
{
	Point XMax, XMin, YMax, YMin;
	double ResizedRadius = Radius * sqrt(Factor);
	XMax = XMin = YMax = YMin = Center;
	XMax.x += ResizedRadius;
	XMin.x -= ResizedRadius;
	YMax.y += ResizedRadius;
	YMin.y -= ResizedRadius;
	if (!isValid(XMax) || !isValid(XMin) || !isValid(YMax) || !isValid(YMin))
		return false;
	Radius = ResizedRadius;
	return true;
}

void CCircle::WestSideTillWeDie()
{
	Center.x /= 2;
}

void CCircle::Save(ofstream& OutFile)
{
	if (FigGfxInfo.isFilled)
	{
		OutFile << "CIRCLE" << " FILLED " << ID << " " << Center.x << " " << Center.y << " "
			<< Radius << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen
			<< " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed
			<< " " << (int)FigGfxInfo.FillClr.ucGreen << " " << (int)FigGfxInfo.FillClr.ucBlue << " "
			<< FigGfxInfo.BorderWdth << endl;
	}
	else
	{
		OutFile << "CIRCLE" << " NO_FILL " << ID << " " << Center.x << " " << Center.y << " "
			<< Radius << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen
			<< " " << (int)FigGfxInfo.DrawClr.ucBlue << " "
			<< FigGfxInfo.BorderWdth << endl;
	}

}

void CCircle::Load(ifstream & Loadfile)
{
	int Red, Green, Blue, Number;
	string Type;
	Point P1;
	Loadfile >> Type;
	Loadfile >> ID >> P1.x >> P1.y >> Radius >> Red >> Green >> Blue;
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
	Center = P1;
	Loadfile >> FigGfxInfo.BorderWdth;
	return;
}
bool CCircle::isFigureType(CFigure * checked)
{
	if (dynamic_cast<CCircle*>(checked) != NULL)
		return true;
	else
		return false;
}
int CCircle::getDimensionValue()
{
	return 3.14*Radius*Radius;
}

CCircle::~CCircle()
{}
