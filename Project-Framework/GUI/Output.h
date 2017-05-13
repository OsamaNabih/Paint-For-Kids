#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void DrawDropMenu(int x);

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const;//Clears the tool Bard

	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawCir(Point P1, double r, GfxInfo CirGfxInfo, bool selected) const;
	void DrawTrian(Point P1, Point P2, Point P3, GfxInfo TrianGfxInfo, bool selected=false) const;
	void DrawLin(Point P1, Point P2,  GfxInfo LineGfxInfo, bool selected=false) const;
	
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	
	void setCrntPenWidth(int x);
	void setCrntPenColor(color x);

	color getCrntDrawColor() const;	//get current drwawing color
	void  getclickedcolor(double & Red, double & Green, double & Blue, int x, int y);
	color getCrntFillColor() const;	//get current filling color
	int   getCrntPenWidth() const;		//get current pen width
	void  setCrntFillColor(color);
	bool  getFillMode() const;
	void setFillMode(bool);
	void setInterfaceMode(int);
	void setBackgroundColor(color);
	~Output();
};

#endif