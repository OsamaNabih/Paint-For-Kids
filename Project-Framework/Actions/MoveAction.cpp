#include "MoveAction.h"
#include "../Figures/CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


MoveAction::MoveAction(ApplicationManager *pApp):Action(pApp)
{
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure** SelectedFigs = pManager->GetSelectedFigures();
	Point Max, Min, tempMax, tempMin, OldMidPoint, NewMidPoint, AxesTranslation;
	Max.x = Max.y = 0;
	Min.x = Min.y = 200000;
	if (SelectedFigs == NULL)
	{
		pOut->PrintMessage("No figures are selected, unable to move");
		return;
	}
	int i = 0;
	while (SelectedFigs[i] != NULL)
	{
		tempMax = SelectedFigs[i]->CalculateMaxCoordinates();
		tempMin = SelectedFigs[i]->CalculateMinCoordinates();
		if (tempMax.x > Max.x)
			Max.x = tempMax.x;
		if (tempMax.y > Max.y)
			Max.y = tempMax.y;
		if (tempMin.x < Min.x)
			Min.x = tempMin.x;
		if (tempMin.y < Min.y)
			Min.y = tempMin.y;
		i++;
	}
	OldMidPoint.x = Min.x + ((Max.x - Min.x) / 2);
	OldMidPoint.y = Min.y + ((Max.y - Min.y) / 2);
	pOut->PrintMessage("Please click a point to move the selected figures to");
	pIn->GetPointClicked(NewMidPoint.x, NewMidPoint.y);
	if (!isValid(NewMidPoint))
	{
		pOut->PrintMessage("Invalid point, please select another action");
		return;
	}
	AxesTranslation.x = NewMidPoint.x - OldMidPoint.x;
	AxesTranslation.y = NewMidPoint.y - OldMidPoint.y;
	Max.x += AxesTranslation.x;
	Max.y += AxesTranslation.y;
	Min.x += AxesTranslation.x;
	Min.y += AxesTranslation.y;
	if (!isValid(Max) || !isValid(Min))
	{
		pOut->PrintMessage("Error: not all figures fit inside the window, please choose another action");
		return;
	}
	i = 0;
	while (SelectedFigs[i] != NULL)
	{
		SelectedFigs[i]->MoveFig(AxesTranslation);
		i++;
	}
	pOut->ClearDrawArea();
}

void MoveAction::Execute()
{
	ReadActionParameters();
}
