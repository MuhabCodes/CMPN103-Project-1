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

	CellPosition* pCellPosition = pPlayer->GetCell()->GetCellPosition()

	if (pGrid->GetNextSnake(pCellPosition))
	{
		pGrid->UpdatePlayerCell(pPlayer, pCellPosition);
		pGrid->GetNextSnake(pCellPosition)->Apply(pGrid, pPlayer);
		pGrid->PrintErrorMessage("Player moved to the next snake ! Click to continue ...");
	}
	else
	{
		pGrid->PrintErrorMessage("No snakes ahead ! Click to continue ...");
	}
}

void CardFour::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << endl;
}
