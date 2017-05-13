#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_Trn,		//Triangle item in men
	ITM_Line,		//Line item in menu
	ITM_BColor,		//Border Color item in menu 
	ITM_FColor,		//Fill Color item in menu 
	ITM_CBGColor,	//Change BackGround color 
	ITM_Delete,		//Delete figure
	ITM_Move,		//Move figure
	ITM_ReSize,	//Resize figure item in menu
	ITM_Rotate,
	ITM_SendBack,	//	
	ITM_BringFront,	//
	ITM_Save,		//
	ITM_Load,		//	
	ITM_SFigure,	//Select Figure item in menu
	ITM_FillMode,		//Choose Color item in menu
	ITM_BorderWidth,
	ITM_ZoomIn,		//Zoom in whole drawing area
	ITM_ZoomOut,	//Zoom out whole drawing area 
	
	
	ITM_Copy,		//Copy figure
	ITM_Paste,		//Paste figure
	ITM_Cut,		//Cut figure
	
	ITM_SwitchToPlay,//
	ITM_EXIT,		//Exit item
	

	//TODO: Add more items names here

	
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum DrawItemCount
{
	ITM_PickAndHide, //
	ITM_ScrambleAndFind,//
	ITM_SwitchToDraw,	//

	Draw_Item_Count
};
enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum DropMenu
{
	DM_CHANGEBORDERWIDTH,
	DM_CHANGEDRAWCOLOR,
	DM_CHANGEFILLCOLOR,
	DM_CHANGEBACKGROUND,
	DM_RESIZE,
	DM_PickAndHide,
	//TODO: add more shit


	DRAW_DM_COUNT
};



__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool FillMode;
	/// Add more members if needed
	
}UI;	//create a global object UI

#endif