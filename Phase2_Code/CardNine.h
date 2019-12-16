#pragma once
#include "Card.h"

class CardNine :public Card
{	

	CellPosition cellpos;

public:

	CardNine(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void ReadCardParameters(Grid * pGrid);
	
	~CardNine();
};

