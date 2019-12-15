#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp) {}

DeleteGameObjectAction::~DeleteGameObjectAction() {}

void DeleteGameObjectAction::ReadActionParameters()
{
	// sets the pointers to the grid, the input, and the output
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// gets the cell position of the object to be deleted
	pOut->PrintMessage("Delete Object: Click on its Cell ...");
	objPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	// sets the parameters of the object (objPos)
	ReadActionParameters();

	// sets the pointers
	Grid* pGrid = pManager->GetGrid();

	// deletes the object if there is an object
	if (pGrid->GetGameObject(objPos))
	{
		pGrid->RemoveObjectFromCell(objPos);
	}
	else
	{
		pGrid->PrintErrorMessage("Error: Cell has no object ! Click to continue ...");
	}
}
