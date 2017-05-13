#include"LoadAction.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CTriangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->DeleteALLFigures();
	pOut->PrintMessage("Enter The File Name");
	string FileName = pIn->GetSrting(pOut);
	ifstream LoadFile("Graphs/" + FileName + ".txt", ios::in);
	int Red, Green, Blue, Number, counter = 0;
	string Type;
	Point P1, P2, P3;
	P1.x = P1.y = P2.x = P2.y = P3.x = P3.y = 0;
	color shit = color(0, 0, 0);
	GfxInfo dummydummy;
	dummydummy.BorderWdth = 0;
	dummydummy.DrawClr = shit;
	dummydummy.FillClr = shit;
	dummydummy.isFilled = false;

	if (!LoadFile.eof())
	{
		LoadFile >> Red >> Green >> Blue;
		UI.DrawColor.ucRed = Red;
		UI.DrawColor.ucGreen = Green;
		UI.DrawColor.ucBlue = Blue;
		LoadFile >> Red >> Green >> Blue;
		UI.FillColor.ucRed = Red;
		UI.FillColor.ucGreen = Green;
		UI.FillColor.ucBlue = Blue;
		LoadFile >> Red >> Green >> Blue;
		UI.BkGrndColor.ucRed = Red;
		UI.BkGrndColor.ucGreen = Green;
		UI.BkGrndColor.ucBlue = Blue;
		LoadFile >> Number;
		while (counter < Number)
		{
			LoadFile >> Type;
			switch (Type[0])
			{
			case 82:
			{
				CRectangle*Rect = new CRectangle(P1, P2, dummydummy);
				pManager->AddFigure(Rect);
			}
			break;
			case 76:
			{
				CLine*Lin = new CLine(P1, P2, dummydummy);
				pManager->AddFigure(Lin);
			}
			break;
			case 84:
			{
				CTriangle*Tri = new CTriangle(P1, P2, P3, dummydummy);
				pManager->AddFigure(Tri);
			}
			break;
			case 67:
			{
				CCircle*Circ = new CCircle(P1, 0, dummydummy);
				pManager->AddFigure(Circ);
			}
			break;
			}
			counter++;
			pManager->LoadFile(LoadFile);
		}

	}

}
void LoadAction::Execute()
{
	ReadActionParameters();
}