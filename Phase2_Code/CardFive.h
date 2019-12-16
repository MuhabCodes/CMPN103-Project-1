#pragma once
#include "Card.h"
#include"Grid.h"

class CardFive :public Card
{

public:

	CardFive(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, GameObjectType Type);
	
	virtual ~CardFive();
};
