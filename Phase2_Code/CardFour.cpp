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

	CellPosition CP(pPlayer->GetStepCount());

	Snake* nearest_snake = pGrid->GetNextSnake(CP);

	if (nearest_snake == NULL)
	{
		pGrid->PrintErrorMessage("No snakes ahead ! Click to continue ...");
		return;
	}
	else
	{
		pGrid->UpdatePlayerCell(pPlayer, nearest_snake->GetPosition());
		pGrid->PrintErrorMessage("Player moved to the next snake ! Click to continue ...");
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
