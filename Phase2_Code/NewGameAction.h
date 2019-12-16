#pragma once
#include "Action.h"
class NewGameAction :public Action
{
	
	// no need for private members because the functionality doesn't require any changing parameters

public:

	NewGameAction(ApplicationManager* pApp);
	
	virtual void ReadActionParameters();
	
	virtual void Execute();
	
	virtual ~NewGameAction();

};

