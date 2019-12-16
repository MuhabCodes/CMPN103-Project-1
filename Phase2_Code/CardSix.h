#pragma once
#include "Card.h"
#include"Grid.h"

class CardSix :public Card
{
public:

	CardSix(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, GameObjectType Type);

	virtual ~CardSix();
};
