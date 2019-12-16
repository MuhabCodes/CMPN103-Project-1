#pragma once
#include "Action.h"
class CopyAction :
	public Action
{
	
	Card* copiedCard;

public:
	CopyAction(ApplicationManager * pApp); // 

	virtual void ReadActionParameters(); 

	virtual void Execute();
	~CopyAction();
};

