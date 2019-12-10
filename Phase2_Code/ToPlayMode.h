#pragma once
#include "Action.h"
class ToPlayMode :
	public Action
{
	// no need for private members because the functionaylity doesn't require any changing parameters
public:
	ToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ToPlayMode();
};

