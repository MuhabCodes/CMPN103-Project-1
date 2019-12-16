#include "CardThree.h"

#include "Ladder.h"

CardThree::CardThree( const CellPosition & Pos): Card(Pos)
{
	
	cardNumber = 3;
}

CardThree::~CardThree()
{
	// Virtual void destructor
}

void CardThree::Apply(Grid * pGrid, Player * pPlayer)
{
	
	Input* pIn = NULL;
	pIn = pGrid->GetInput();

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	int x, y;

	pOut->PrintMessage("Moves the player forward to the start of the next ladder");
	pIn->GetCellClicked();
	
	Card::Apply(pGrid, pPlayer);

	CellPosition cp(pPlayer->GetStepCount());

	Ladder* nearest_ladder = pGrid->GetNextLadder(cp);

	if (nearest_ladder == NULL)
	{
		return;
	}
	else
	{
		//pPlayer->SetStepCount(cp.GetCellNum());
		pGrid->UpdatePlayerCell(pPlayer, nearest_ladder->GetPosition());
	}
	/*Cell c();

	if (pPlayer->GetCell()->HasLadder() != NULL) 
	{
		pPlayer->SetCell(&c);
	}*/
}
