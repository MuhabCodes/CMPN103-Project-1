#pragma once
#include "Card.h"
class CardEleven :public Card
{
	//CardEleven parameters:

	// Static datamembers to only set the price and rent for the card once

	static int price;
	static int rent;
	static Player* Owner;

	// Static player pointer to give all cardElevenss the same owner

public:

	CardEleven(const CellPosition& pos);                                      // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid);                         //reads parameters of CardTen which are: price & rent  
	void SetOwner(Player* pPlayer);                                      //Sets the Owner of the Card
	bool IsBought();                                                    //Checks wether this card is already bought or not
	Player* buy(Grid* pGrid, Player* pPlayer);                         //Buying card function
	void pay(Grid* pGrid, Player* pPlayer);                           //decrements the rent value from the passing player
	virtual void Apply(Grid* pGrid, Player* pPlayer);                // Applies the effect of CardTen on the passed Player
	virtual ~CardEleven();                                             // A Virtual Destructor

};

