#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"


InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
	// Constructor to initialize pApp pointer
}

void InputDiceValue::ReadActionParameters()
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

void InputDiceValue::Execute()
{
	ReadActionParameters(); 
	// We call ReadActionParameters() function to print message for the user
	// and prompt the user to enter DiceInput to use it in Execution

	Grid* pGrid = NULL;
	pGrid = pManager->GetGrid();

	Player* pPlayer = pGrid->GetCurrentPlayer();

	// validation to only move the user when the Input is between 
	// 1 and 6 to immitate dice numbers

	if (DiceInput > 0 && DiceInput <= 6)
	{
		pPlayer->Move(pGrid, DiceInput); // move user using
		pGrid->AdvanceCurrentPlayer();
	}


}

InputDiceValue::~InputDiceValue()
{
	// virtual destructor
}