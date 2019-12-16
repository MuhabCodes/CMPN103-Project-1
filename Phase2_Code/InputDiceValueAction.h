#pragma once
#include "Action.h"

class InputDiceValueAction :
	public Action
{

	int DiceInput; // Value of Dice which will be entered by the user 

public:

	InputDiceValueAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValueAction();
};

