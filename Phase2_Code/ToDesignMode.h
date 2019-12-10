#pragma once
#include "Action.h"
class ToDesignMode :
	public Action
{
	// no need for private members because the functionaylity doesn't require any parameters
public:
	ToDesignMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ToDesignMode();
};

