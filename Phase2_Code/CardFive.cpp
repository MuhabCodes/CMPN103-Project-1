#include "CardFive.h"



CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5;
}

void CardFive:: Apply(Grid* pGrid, Player* pPlayer) 
{

	Card::Apply(pGrid, pPlayer);
	pPlayer->Move(pGrid, pPlayer->GetDiceNum());
	pGrid->UpdateInterface();
}

void CardFive::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << endl;
}

CardFive::~CardFive()
{
	// Virtual void destructor
}
