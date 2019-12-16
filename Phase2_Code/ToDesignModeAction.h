#pragma once
#include "Action.h"
class ToDesignModeAction :public Action
{
	// no need for private members because the functionaylity doesn't require any parameters
public:
	ToDesignModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ToDesignModeAction();
};

