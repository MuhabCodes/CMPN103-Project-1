#pragma once
#include "Card.h"

class CardThree :public Card
{

public:
		
	CardThree(const CellPosition & pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, GameObjectType Type);

	virtual ~CardThree();

};

