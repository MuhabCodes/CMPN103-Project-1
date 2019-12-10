#pragma once
#include "Action.h"
class AddSnakeAction :
	public Action
{
	// Action Paramters 

	CellPosition startPos;
	CellPosition endPos;

	// snake parameters to be read in the ReadActionParameters() function

public:

	AddSnakeAction(ApplicationManager* pApp); // Snake action Constructor

	virtual void ReadActionParameters(); // startPos and endPos reading function

	virtual void Execute(); // function to excute the "Snake" action

	virtual ~AddSnakeAction(); // Virtual Destructor 
};


