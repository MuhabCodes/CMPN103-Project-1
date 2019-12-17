#pragma once
#include "Action.h"
class PasteAction :
	public Action
{
	Card* pastedCard;
	Grid * pGrid;
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters(); 

	virtual void Execute();

	~PasteAction();
};

