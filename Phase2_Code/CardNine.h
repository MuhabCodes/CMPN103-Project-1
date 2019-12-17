#pragma once
#include "Card.h"

class CardNine :public Card
{	
	static CellPosition cellpos;
	static bool initiated;
	bool initial;

public:

	CardNine(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Save(ofstream& OutFile, GameObjectType Type);

	virtual bool Load(ifstream& InFile);
	
	~CardNine();
};

