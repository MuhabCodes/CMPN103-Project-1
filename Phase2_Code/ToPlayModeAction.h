#pragma once
#include "Action.h"
class ToPlayModeAction :
	public Action
{
	// no need for private members because the functionaylity doesn't require any changing parameters
public:
	ToPlayModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ToPlayModeAction();
};

