#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE ;	//Background COLOR LIGHTGOLDENRODYELLOW
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
void Output::ClearToolBar()const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	ClearToolBar();
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_Line] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_Trn] = "images\\MenuItems\\Menu_Trn.jpg";
	MenuItemImages[ITM_BColor] = "images\\MenuItems\\Menu_BoColor.jpg";
	MenuItemImages[ITM_FColor] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_CBGColor] = "images\\MenuItems\\Menu_CBGColor.jpg";
	MenuItemImages[ITM_SFigure] = "images\\MenuItems\\Menu_SFigure.jpg";
	MenuItemImages[ITM_CColor] = "images\\MenuItems\\Menu_CColor.jpg";
	MenuItemImages[ITM_BorderWidth] = "images\\Menuitems\\Menu_BorderWidth.jpg";
	MenuItemImages[ITM_ReSize] = "images\\MenuItems\\Menu_ReFigure.jpg";
	MenuItemImages[ITM_Rotate] = "images\\MenuItems\\Menu_Rotate.jpg";
	MenuItemImages[ITM_ZoomIn] = "images\\MenuItems\\Menu_ZoomIn.jpg";
	MenuItemImages[ITM_ZoomOut] = "images\\MenuItems\\Menu_ZoomOut.jpg";
	MenuItemImages[ITM_SendBack] = "images\\MenuItems\\Menu_SendBack.jpg";
	MenuItemImages[ITM_BringFront] = "images\\MenuItems\\Menu_BringFront.jpg";
	MenuItemImages[ITM_Delete] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_Move] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_Copy] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_Paste] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_Cut] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_Save] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_Load] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_SwitchToPlay] = "images\\MenuItems\\Menu_PlayMode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);
	//for (int i = 4; i < (DRAW_ITM_COUNT-1); i++)		// I NEED TO HARDCODE THE RANGE FOR THIS LOOP AND 
	//{
	//	pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, 25, 25);		// FOR THIS ONE SO I KNOW MY RANGE 

	//}
	/*for (int i =4; i < DRAW_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 25, 25, 25);
	}
	pWind->DrawImage(MenuItemImages[DRAW_ITM_COUNT], (4 * UI.MenuItemWidth + ((DRAW_ITM_COUNT - 5) * 25)), 0,UI.MenuItemWidth,UI.ToolBarHeight);*/


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	//pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string DrawItemImages[Draw_Item_Count];
	DrawItemImages[ITM_PickAndHide] = "images\\MenuItems\\Menu_PickAndHide.jpg";
	DrawItemImages[ITM_ScrambleAndFind] = "images\\MenuItems\\Menu_ScrambleAndFind.jpg";
	DrawItemImages[ITM_SwitchToDraw] = "images\\MenuItems\\Menu_DrawMode.jpg";

	ClearToolBar();
	for (int i = 0; i<3; i++)
		pWind->DrawImage(DrawItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight+2, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawCir(Point P1,double r, GfxInfo CirGfxInfo, bool selected) const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CirGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}
	pWind->DrawCircle(P1.x, P1.y, r, style);
}

void Output::DrawTrian(Point P1, Point P2,Point P3,GfxInfo TrianGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrianGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr,TrianGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TrianGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrianGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}
	
	pWind->DrawTriangle(P1.x, P1.y,P2.x, P2.y,P3.x,P3.y ,style);
}

void Output::DrawLin(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	if(P1.y < 50 || P2.y <50 || P1.y > 650 || P2.y > 650)
	{
		PrintMessage("Choose points inside the drawing area , click anywhere to continue");
		Input*PIN = CreateInput();
		int x, y;
		PIN->GetPointClicked(x, y);
		delete PIN;
		return;
	}
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

