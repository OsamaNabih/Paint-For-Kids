#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				
				case ITM_RECT: return DRAW_RECT;
				case ITM_CIRC: return DRAW_CIRC;
				case ITM_Trn: return DRAW_TRI;
				case ITM_Line: return DRAW_LINE;
				case ITM_BColor:return CHNG_BORD_CLR;
				case ITM_FColor:return CHNG_FILL_CLR;
				case ITM_CBGColor:return CHNG_BK_CLR;
				case ITM_Delete:return DEL;
				case ITM_Move:return MOVE;
				case ITM_ReSize:return RESIZE;
				case ITM_Rotate:return ROTATE;
				case ITM_SendBack:return SEND_BACK;
				case ITM_BringFront:return BRNG_FRNT;
				case ITM_Save:return SAVE;
				case ITM_Load:return LOAD;
				case ITM_SFigure:return SELECT_FIGURE;
				case ITM_FillMode:return FILL_MODE;
				case ITM_BorderWidth:return CHANGE_BWIDTH;
				case ITM_ZoomIn:return ZOOM_IN;
				case ITM_ZoomOut:return ZOOM_OUT;
				case ITM_Copy:return COPY;
				case ITM_Paste:return PASTE;
				case ITM_Cut : return CUT;
				case ITM_SwitchToPlay:return TO_PLAY;


			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickOrderItem = (x / UI.MenuItemWidth);


			switch (ClickOrderItem)
			{
			case ITM_PickAndHide:return PCK_HIDE;
			case ITM_ScrambleAndFind:return SCM_FIND;
			case ITM_SwitchToDraw:return TO_DRAW;
			default:return EMPTY;

			}
				
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return STATUS;	//just for now. This should be updated /// i have changed from TO PLAY TO Status ass i dont understand
						//why it should return to play as to play is a button 
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
