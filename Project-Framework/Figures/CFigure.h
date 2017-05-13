#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.
	static int NextID;
public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual CFigure* CopyFigWithDefaultConstructor() = 0;
	virtual CFigure* CopyFigWithCopyConstructor() = 0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool IsPointHere(Point) const = 0;
	virtual void WestSideTillWeDie() = 0;
	color GetColor();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void ChngBoWidth(int x);
	void SetID(int ID);
	int GetId();
	static void setNextID(int ID);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	virtual bool Resize(float Factor) = 0;	//Resize the figure
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
	virtual Point CalculateMaxCoordinates() const = 0;
	virtual Point CalculateMinCoordinates() const = 0;
	virtual void MoveFig(Point) = 0;
	virtual bool isFigureType(CFigure* Checked) = 0;
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual int getDimensionValue() = 0;
	virtual ~CFigure();

protected: bool isValid(Point P); //utility function to check if point is inside drawing area
};

#endif