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
	int x;
	int y;
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	Card::Apply(pGrid, pPlayer);
	CellPosition CP(pPlayer->GetStepCount());
	Snake* nearest_snake = pGrid->GetNextSnake(CP);
	if (nearest_snake != NULL)
		CP = nearest_snake->GetPosition();

	pPlayer->SetStepCount(CP.GetCellNum());
}

