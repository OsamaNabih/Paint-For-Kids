#include "ScrambleAndFind.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <time.h>
//#include <stdlib.h>

ScrambleAndFind::ScrambleAndFind(ApplicationManager * pApp) :Action(pApp)
{
}


ScrambleAndFind::~ScrambleAndFind()
{
}

void ScrambleAndFind::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure** LeftFigs = pManager->CopyFigList();
	if (LeftFigs == NULL)
	{
		pOut->PrintMessage("No figures drawn");
		return;
	}
	pOut->PrintMessage("ScrambleAndFind Mode: Activated!");
	int i = 0;
	int Count, RandomIndex;
	Point RandomLocation, MinCoordinates, MaxCoordinates;
	while (LeftFigs[i] != NULL)
	{
		LeftFigs[i]->WestSideTillWeDie();
		i++;
	}
	Count = i;
	CFigure** RightFigs = new CFigure*[Count];
	for (int i = 0; i < Count; i++)
	{
		RightFigs[i] = NULL;
	}
	i = 0;
	while (LeftFigs[i] != NULL)
	{
		srand(time(NULL));
		RandomIndex = rand() % Count;
		while (RightFigs[RandomIndex] != NULL)
		{
			RandomIndex = rand() % Count;
		}
		RightFigs[RandomIndex] = LeftFigs[i]->CopyFigWithCopyConstructor();
		MaxCoordinates = LeftFigs[i]->CalculateMaxCoordinates();
		MinCoordinates = LeftFigs[i]->CalculateMinCoordinates();
		MinCoordinates.x = (UI.width / 2) - MinCoordinates.x - 5;
		MaxCoordinates.x = UI.width - MaxCoordinates.x - 5;
		MaxCoordinates.y = UI.height - UI.StatusBarHeight - MaxCoordinates.y - 5;
		MinCoordinates.y = UI.ToolBarHeight - MinCoordinates.y + 5;
		RandomLocation.x = rand() % (MaxCoordinates.x - MinCoordinates.x) + MinCoordinates.x;
		RandomLocation.y = rand() % (MaxCoordinates.y - MinCoordinates.y) + MinCoordinates.y;
		RightFigs[RandomIndex]->MoveFig(RandomLocation);
		i++;
	}
	pOut->ClearDrawArea();
	i = 0;
	DrawList(LeftFigs, Count);
	DrawList(RightFigs, Count);
	Point P1, P2;
	P1.x = P2.x = UI.width / 2;
	P1.y = UI.ToolBarHeight;
	P2.y = UI.height - UI.StatusBarHeight;
	GfxInfo LineInfo;
	LineInfo.FillClr = pOut->getCrntFillColor();
	LineInfo.BorderWdth = pOut->getCrntPenWidth();
	LineInfo.DrawClr = BLACK;
	pOut->DrawLin(P1, P2, LineInfo);
	int ValidClicks, InvalidClicks, j;
	ValidClicks = InvalidClicks = 0;
	Point PointClicked;
	bool Valid;
	//for (i = Count - 1; i >= 0; i--)
	//{
	//	LeftFigs[i]->SetSelected(true);
	//	DrawList(LeftFigs, Count);
	//	DrawList(RightFigs, Count);
	//	pOut->PrintMessage("Select the identical figure");
	//	for (j = 0; j < Count; j++)
	//	{
	//		if (RightFigs[j] != NULL)
	//		{
	//			if (RightFigs[j]->GetId() == LeftFigs[i]->GetId())
	//				break;
	//		}
	//	}
	//	do
	//	{
	//		pIn->GetPointClicked(PointClicked.x, PointClicked.y);
	//		Valid = RightFigs[j]->IsPointHere(PointClicked);
	//		if (Valid)
	//		{
	//			ValidClicks++;
	//			break;
	//		}
	//		InvalidClicks++;
	//		pOut->PrintMessage("Try again!");
	//	} while (!Valid);
	//	delete LeftFigs[i];
	//	delete RightFigs[j];
	//	LeftFigs[i] = RightFigs[j] = NULL;
	//	pOut->ClearDrawArea(); 
	//	pOut->DrawLin(P1, P2, LineInfo);
	//	DrawList(LeftFigs, Count);
	//	DrawList(RightFigs, Count);
	//}

	for (i = Count - 1; i >= 0; i--)
	{
		for (j = 0; j < Count; j++)
		{
			if (LeftFigs[j] != NULL)
			{
				if (RightFigs[i]->GetId() == LeftFigs[j]->GetId())
					break;
			}
		}
		LeftFigs[j]->SetSelected(true);
		LeftFigs[j]->Draw(pOut);
		DrawList(RightFigs, Count);
		pOut->PrintMessage("Select the identical figure");
		do
		{
			pIn->GetPointClicked(PointClicked.x, PointClicked.y);
			Valid = RightFigs[i]->IsPointHere(PointClicked);
			if (Valid)
			{
				ValidClicks++;
				break;
			}
			InvalidClicks++;
			pOut->PrintMessage("Try again!");
		} while (!Valid);
		delete LeftFigs[j];
		delete RightFigs[i];
		LeftFigs[j] = RightFigs[i] = NULL;
		pOut->ClearDrawArea();
		pOut->DrawLin(P1, P2, LineInfo);
		DrawList(LeftFigs, Count);
		DrawList(RightFigs, Count);
	}
	string s = to_string(ValidClicks);
	string s2 = to_string(InvalidClicks);
	string Accuracy = to_string(((float)ValidClicks / (ValidClicks + InvalidClicks)) * 100) + "%";
	pOut->PrintMessage("Valid clicks: " + s + " Invalid clicks: " + s2 + " Accuracy: " + Accuracy);
	pOut->ClearDrawArea();
}
void ScrambleAndFind::Execute()
{
	ReadActionParameters();
}

void ScrambleAndFind::DrawList(CFigure** List, int Count)
{
	Output* pOut = pManager->GetOutput();
	int i = 0;
	while (i < Count)
	{
		if (List[i] != NULL)
			List[i]->Draw(pOut);
		i++;
	}
}