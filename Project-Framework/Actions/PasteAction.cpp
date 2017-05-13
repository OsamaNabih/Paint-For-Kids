#include "PasteAction.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PasteAction::PasteAction(ApplicationManager *pApp) :Action(pApp)
{
}


void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure** Copied = pManager->GetCopied();
	Point Max, Min, tempMax, tempMin, OldMidPoint, NewMidPoint, AxesTranslation;
	Max.x = Max.y = 0;
	Min.x = Min.y = 200000;
	if (Copied == NULL)
	{
		pOut->PrintMessage("No figures are copied/cut, unable to paste");
		return;
	}
	int i = 0;
	while (Copied[i] != NULL)
	{
		tempMax = Copied[i]->CalculateMaxCoordinates();
		tempMin = Copied[i]->CalculateMinCoordinates();
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
	pOut->PrintMessage("Please click a point to paste the selected figures to");
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
	while (Copied[i] != NULL)
	{
		Copied[i]->MoveFig(AxesTranslation);
		i++;
	}
	pManager->AddFromClipBoard();
	pOut->ClearDrawArea();
}

void PasteAction::Execute()
{
	ReadActionParameters();
}

