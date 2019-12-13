#include "Card.h"


class CardTen :
	public Card
{
	//CardTen parameters:
	int price;
	int rent;
	Player* Owner;

public:
	CardTen(const CellPosition& pos);                                       // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid);                          //reads parameters of CardTen which are: price & rent  
	void SetOwner(Player* pPlayer);                                      //Sets the Owner of the Card
	Player* GetOwner();                                                  //A Getter for the card's Owner
	bool IsBought();                                                    //Checks wether this card is already bought or not
	Player* buy(Grid* pGrid, Player* pPlayer);                         //Buying card function
	void pay(Grid* pGrid, Player* pPlayer);                           //decrements the rent value from the passing player
	virtual void Apply(Grid* pGrid, Player* pPlayer);                // Applies the effect of CardTen on the passed Player
	virtual ~CardTen();                                             // A Virtual Destructor
};



