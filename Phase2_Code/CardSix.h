#pragma once
#include "Card.h"
#include"Grid.h"

class CardSix :public Card
{
public:

	CardSix(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardSix();
};
