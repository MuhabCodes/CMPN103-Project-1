#pragma once
#include "Action.h"
class CutAction :
	public Action
{
	Card* cuttedCard;
public:
	CutAction( ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();


	~CutAction();
};

