#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initialize pManager pointer
}

AddSnakeAction::~AddSnakeAction()
{
	// Virtual Destructor
}

void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters

	
	// Clear messages
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid();

	// verify that the start cell is above the end cell
	if (startPos.VCell() >= endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error: The Start cell must be under the End cell ! Click to continue ...");
		return;
	}

	// verify that the start cell and the end cell are in the same column
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Error: The Start Cell and the End Cell must be in the same column ! Click to continue ...");
		return;
	}

	if (pGrid->GetGameObject(startPos))
	{
		pGrid->PrintErrorMessage("Error: The Start Cell cannot be the Start Cell of another object ! Click to continue ...");
		return;
	}

	if (pGrid->HasEnd(startPos))
	{
		pGrid->PrintErrorMessage("Error: The Start Cell cannot be the End Cell of another object ! Click to continue ...");
		return;
	}

	if (pGrid->GetGameObject(endPos))
	{
		pGrid->PrintErrorMessage("Error: The End Cell cannot be the Start Cell of another object ! Click to continue ...");
		return;
	}

	bool added = pGrid->AddObjectToCell(pSnake);

	if (added)
	{
		pGrid->SetEnd(endPos, true);
	}
	else
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Two snakes cannot overlap ! Click to continue ...");
	}
}
