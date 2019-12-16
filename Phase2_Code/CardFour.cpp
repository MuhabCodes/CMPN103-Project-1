#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition & Pos) :Card(Pos)
{
	cardNumber = 4;
}

CardFour::~CardFour()
{
	// Virtual void Destructor
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); 

	Cell* pCell = NULL;
	pCell = pPlayer->GetCell();
	CellPosition pCellPosition;
	pCellPosition = pCell->GetCellPosition();

	if (pGrid->GetNextSnake(pCellPosition))
	{
		pGrid->UpdatePlayerCell(pPlayer, pGrid->GetNextSnake(pCellPosition)->GetPosition());

		pGrid->GetNextSnake(pCellPosition)->Apply(pGrid, pPlayer);
	}
}

