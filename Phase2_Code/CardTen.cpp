#include "CardTen.h"

CardTen::CardTen(const CellPosition& pos) : Card(pos)
{
	cardNumber = 10;
}
void CardTen::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	Output* pOut = NULL;
	pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardTen: Enter its price value: ");
	int p = pIn->GetInteger(pOut);
	while (p <= 0)                                 //price validation
	{
		pOut->PrintMessage("New CardTen: Invalid, Re-enter its price value: ");
		p = pIn->GetInteger(pOut);
	}
	price = p;
	pOut->PrintMessage("CardTen price = " + to_string(p));

	pOut->PrintMessage("New CardTen: Enter its rent value : ");
	int r = pIn->GetInteger(pOut);
	while (r <= 0)                              //rent validations
	{
		pOut->PrintMessage("New CardTen: Invalid, Re-enter its rent value: ");
		r = pIn->GetInteger(pOut);
	}
	rent = r;
	pOut->PrintMessage("CardTen rent = " + to_string(r));
	pOut->ClearStatusBar();

}
void CardTen::SetOwner(Player* pPlayer)
{
	if ((pPlayer->GetWallet()) >= price)
	{
		Owner = pPlayer;
	}
}
Player* CardTen::GetOwner()
{
	return Owner;
}

bool CardTen::IsBought()
{
	if (Owner == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}


}
Player* CardTen::buy(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	Output* pOut = NULL;
	pOut = pGrid->GetOutput();
	Player* p = pGrid->GetCurrentPlayer();                     //Gets the current player.
	bool b = IsBought();
	if (b == false)                                            //checks if no player owns the card.
	{
		pOut->PrintMessage("Do you want to buy this card? (Y/N)");
		string a = pIn->GetString(pOut);
		if (a == "Y" || a == "y")
		{
			SetOwner(p);                                      //setOwner
			if (Owner == NULL)
			{
				pOut->PrintMessage("Invalid, No enough amount in wallet");
			}
		}
		else if (a == "N" || a == "n")
		{
			pOut->ClearStatusBar();
		}
		else
		{
			pOut->PrintMessage("Invalid Character");
		}
	}
	return p;

}
void CardTen::pay(Grid* pGrid, Player* pPlayer)
{
	bool b = IsBought();
	Player* p = pGrid->GetCurrentPlayer();
	if (b == true)                                                      //checks if the current card had an owner
	{
		if (!(Owner == p))                                           //Checks if the owner is not the current player
		{
			int i = p->GetstepCount();                              //step count which is the same as player's cellNum
			int j = position.GetCellNum();                         //The current cell position of the game object

			if (i == j)                                           //Checks if the current players is standing on this card
			{
				int w = p->GetWallet();                          //Gets the amount in the wallet of the current player
				w = w - rent;                                   //decrements the rent value
				p->SetWallet(w);
				int ww = Owner->GetWallet();
				ww = ww + rent;                                //increment the owners' walet by the rent.
				Owner->SetWallet(ww);
			}
		}
	}

}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);
	SetOwner(pPlayer);
	buy(pGrid, pPlayer);
	pay(pGrid, pPlayer);
}
CardTen::~CardTen()
{

}