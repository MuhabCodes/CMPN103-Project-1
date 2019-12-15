#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	
	// Initializing a grid pointer using pManager
	Grid* pGrid = NULL;
	pGrid = pManager->GetGrid();
	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	
	//Using bool function GetEndGame to declare True/False for the if condition

	bool flag = pGrid->GetEndGame();

	if (!flag)
	{

		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		pOut->PrintMessage("You just rolled " + to_string(diceNumber) + " ");
		Player* pPlayer = pGrid->GetCurrentPlayer(); // step 3 - getting current player
		pPlayer->Move(pGrid, diceNumber); // step 4 - moving current player using Move fn
		pGrid->AdvanceCurrentPlayer(); // step 5 - Advancing to next player

	}
	else
	{
		pOut->PrintMessage("Game finished!");
	}

	// 3- Get the "current" player from pGrid
	// 4- Move the currentPlayer using function Move of class player
	// 5- Advance the current player number of pGrid


	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
