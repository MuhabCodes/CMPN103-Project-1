#pragma once
#include "Action.h"
class DeleteGameObjectAction :public Action
{
	CellPosition objPos; // only data member needed is the location of the object to be deleted
public:
	DeleteGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~DeleteGameObjectAction();
};

