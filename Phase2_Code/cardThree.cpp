#include "CardThree.h"

#include "Ladder.h"
#include "Grid.h"

CardThree::CardThree(const CellPosition & Pos): Card(Pos)
{
	cardNumber = 3;
}

CardThree::~CardThree()
{
	// Virtual void destructor
}

void CardThree::Apply(Grid * pGrid, Player * pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Cell* pCell = NULL;
	pCell = pPlayer->GetCell();
	CellPosition pCellPosition;
	pCellPosition = pCell->GetCellPosition();

	if (pGrid->GetNextLadder(pCellPosition)) 
	{
		pGrid->UpdatePlayerCell(pPlayer, pGrid->GetNextLadder(pCellPosition)->GetPosition());

		pGrid->GetNextLadder(pCellPosition)->Apply(pGrid, pPlayer);
	}
}
