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

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	Input* pIn = NULL;
	pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached card 8, player" + to_string(pPlayer->GetPlayerNum()) + " cannot move, press anywhere to continue ");
	pIn->GetCellClicked();




}

CardEight::~CardEight()
{
	// Virtual void destructor
}