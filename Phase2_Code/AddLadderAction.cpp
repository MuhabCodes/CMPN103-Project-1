#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
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

	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	
	// verify that the start cell is under the end cell
	if (startPos.VCell() <= endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error: The Start cell must be under the End cell ! Click to continue ...");
		delete pLadder;
		return;
	}

	// verify that the start cell and the end cell are in the same column
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("Error: The Start Cell and the End Cell must be in the same column ! Click to continue ...");
		delete pLadder;
		return;
	}

	if (pGrid->GetGameObject(startPos))
	{
		pGrid->PrintErrorMessage("Error: The Start Cell cannot be the Start Cell of another object ! Click to continue ...");
		delete pLadder;
		return;
	}

	if (pGrid->HasEnd(startPos))
	{
		pGrid->PrintErrorMessage("Error: The Start Cell cannot be the End Cell of another object ! Click to continue ...");
		delete pLadder;
		return;
	}

	if (pGrid->GetGameObject(endPos))
	{
		pGrid->PrintErrorMessage("Error: The End Cell cannot be the Start Cell of another object ! Click to continue ...");
		delete pLadder;
		return;
	}

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// Flag end cell if added
	if (added)
	{
		pGrid->SetEnd(endPos, true);
	}
	else
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Two ladders cannot overlap ! Click to continue ...");
		delete pLadder;
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
