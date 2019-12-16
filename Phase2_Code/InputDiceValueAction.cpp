#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"


InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
	// Constructor to initialize pApp pointer
}

void InputDiceValueAction::ReadActionParameters()
{
	// Get a grid pointer to use GetInput and GetOutput functions 

	Grid* pGrid = NULL;
	pGrid = pManager->GetGrid();

	Input* pIn = NULL;
	pIn = pGrid->GetInput();

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	// after getting Input and output pointers I can now print messages and take user inputs

	pOut->PrintMessage("Input dice value: ");
	DiceInput = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void InputDiceValueAction::Execute()
{
	ReadActionParameters(); 
	// We call ReadActionParameters() function to print message for the user
	// and prompt the user to enter DiceInput to use it in Execution

	Grid* pGrid = NULL;
	pGrid = pManager->GetGrid();

	Input* pIn = NULL;
	pIn = pGrid->GetInput();

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	// validation to only move the user when the Input is between 
	// 1 and 6 to immitate dice numbers

	//if (DiceInput > 0 && DiceInput <= 6)
	//{
	//	pPlayer->Move(pGrid, DiceInput); // move user using
	//	pGrid->AdvanceCurrentPlayer();
	//}

	pPlayer->Move(pGrid, DiceInput); // move user using
	pGrid->AdvanceCurrentPlayer();

}

InputDiceValueAction::~InputDiceValueAction()
{
	// virtual destructor
}