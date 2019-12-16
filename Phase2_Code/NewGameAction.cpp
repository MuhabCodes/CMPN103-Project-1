#include "NewGameAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
	// initializing the action base clase
} 

NewGameAction::~NewGameAction()
{
	// virtual NewGame Destructor
}

void NewGameAction::ReadActionParameters()
{
	// no parameters required
}

void NewGameAction::Execute()
{

	// create the player mode tool bar

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	CellPosition pResetCell(8,0);

	for (int i = 0; i < 4; i++)
	{
		// pointer to current player
		Player* pPlayer = pGrid->GetCurrentPlayer();

		//Setter function calls to reset current players info 

		pGrid->UpdatePlayerCell(pPlayer, pResetCell);
		pPlayer->SetWallet(100);
		pPlayer->SetTurnCount(0);
		pPlayer->SetStepCount(0);

		// Advance to next player;

		pGrid->AdvanceCurrentPlayer();

	}

	pGrid->UpdateInterface();
}