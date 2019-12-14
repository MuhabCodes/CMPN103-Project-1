#pragma once
#include "Card.h"
// [ CardThirteen ] Summary:
// Its Apply() Function: Gives the player the option to buy this celland all cells containing a card with the same number.
					  //For example, if a player chooses to buy a cell with card 13, he will own all cells having a card 13.
					 //This cell is considered a station for a specific price.
					//Whenever another player moves to a cell owned by another player, he has to pay the rent to the player who owns the cell.

// Its Parameters: The price of the celland the rent are taken as input during grid design  --> ReadCardParameters()

class CardThirteen :public Card
{
	//CardThirteen parameters:

	// Static datamembers to only set the price and rent for the card once

	static int price;
	static int rent;
	static Player* Owner;

	// Static player pointer to give all cardThirteens the same owner

public:

	CardThirteen(const CellPosition& pos);                                      // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid);                         //reads parameters of CardTen which are: price & rent  
	void SetOwner(Player* pPlayer);                                      //Sets the Owner of the Card
	bool IsBought();                                                    //Checks wether this card is already bought or not
	Player* buy(Grid* pGrid, Player* pPlayer);                         //Buying card function
	void pay(Grid* pGrid, Player* pPlayer);                           //decrements the rent value from the passing player
	virtual void Apply(Grid* pGrid, Player* pPlayer);                // Applies the effect of CardTen on the passed Player
	virtual ~CardThirteen();                                             // A Virtual Destructor

};

