#include "CardSeven.h"
#include "RollDiceAction.h"


CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pPlayer = pGrid->GetCurrentPlayer();

	pPlayer->SetAnotherDiceRoll(true);

	
}

void CardSeven::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << endl;
}

CardSeven::~CardSeven()
{

}