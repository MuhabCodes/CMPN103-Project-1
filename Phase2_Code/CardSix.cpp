#include "CardSix.h"



CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}



void CardSix::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->Move(pGrid, -1 * (pPlayer->GetDiceNum()));

	pGrid->UpdateInterface();
}

void CardSix::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << endl;
}

CardSix::~CardSix()
{
	// Virtual void destructor
}