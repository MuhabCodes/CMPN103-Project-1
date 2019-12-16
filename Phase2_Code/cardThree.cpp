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

	CellPosition* pCellPosition = pPlayer->GetCell()->GetCellPosition();

	if (pGrid->GetNextLadder(pCellPosition)) 
	{
		pGrid->UpdatePlayerCell(pPlayer, pCellPosition);
		pGrid->GetNextLadder(pCellPosition)->Apply(pGrid, pPlayer);
		pGrid->PrintErrorMessage("Player moved to the next ladder ! Click to continue ...");
	}
	else
	{
		pGrid->PrintErrorMessage("No ladders ahead ! Click to continue ...");
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
