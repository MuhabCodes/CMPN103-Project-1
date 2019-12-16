#pragma once
#include "Card.h"

class CardFour :public Card
{

public:

	CardFour(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, GameObjectType Type);
	virtual ~CardFour();
};
