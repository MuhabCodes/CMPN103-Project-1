#pragma once
#include "Card.h"
class CardTwo : public Card

{
	// Static int to keep the increment wallet value consistent on all cells with CardTwo

	static int walletAmount; // the wallet value to increase from the player

public:
	CardTwo(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile, GameObjectType Type);

	virtual ~CardTwo();
};


