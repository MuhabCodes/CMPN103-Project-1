#pragma once

#include "Action.h"

class EditCardAction : public Action
{
	// [Action Parameters]
	CellPosition cell;
	int newCardNumber;
	int oldCardNumber;

public:
	EditCardAction(ApplicationManager* pApp);     // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();  

	virtual ~EditCardAction();                // A Virtual Destructor
};

