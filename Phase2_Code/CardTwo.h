#pragma once
#include "Card.h"
class CardTwo :
	public Card
{
	int walletAmount;
public:
	CardTwo(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardTwo();
};


