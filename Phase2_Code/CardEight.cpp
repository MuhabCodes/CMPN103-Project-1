#include "CardEight.h"



CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	
	Card::Apply(pGrid, pPlayer);

	pPlayer = pGrid->GetCurrentPlayer();

	pPlayer->SetIsPrevented(true);

}

CardEight::~CardEight()
{
	// Virtual void destructor
}