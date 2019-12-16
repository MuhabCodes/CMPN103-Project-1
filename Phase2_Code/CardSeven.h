#pragma once
#include "Card.h"
class CardSeven : public Card
{

public:

	CardSeven(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, GameObjectType Type);

	virtual ~CardSeven();

};

