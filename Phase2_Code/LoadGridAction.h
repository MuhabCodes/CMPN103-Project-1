#pragma once
#include "Action.h"

#include <fstream>

class LoadGridAction :
	public Action
{
	string FileName;
public:
	LoadGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~LoadGridAction();
};

