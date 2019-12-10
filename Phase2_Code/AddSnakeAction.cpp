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
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if (startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("end cell and start cell are not in the same column");
	}
	if (startPos.VCell() )


	// Clear messages
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	ReadActionParameters();

	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid();

	bool added = pGrid->AddObjectToCell(pSnake);

	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}
