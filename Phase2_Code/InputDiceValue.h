#pragma once
#include "Action.h"

class InputDiceValue :
	public Action
{

	int DiceInput; // Value of Dice which will be entered by the user 

public:

	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};

