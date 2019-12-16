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
	Card::Apply(pGrid, pPlayer);

	CellPosition cp(pPlayer->GetStepCount());

	Ladder* nearest_ladder = pGrid->GetNextLadder(cp);

	if (nearest_ladder == NULL)
	{
		pGrid->PrintErrorMessage("No ladders ahead ! Click to continue ...");
		return;
	}
	else
	{
		pGrid->UpdatePlayerCell(pPlayer, nearest_ladder->GetPosition());
		pGrid->PrintErrorMessage("Player moved to the next ladder ! Click to continue ...");
	}
}

void CardThree::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << endl;
}
