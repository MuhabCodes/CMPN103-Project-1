#include "CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 11;

}

int CardEleven::price = 0;

int CardEleven::rent = 0;

Player* CardEleven::Owner = NULL;

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = NULL;
	Output* pOut = NULL;

	pIn = pGrid->GetInput();
	pOut = pGrid->GetOutput();

	while (price <= 0)                                 //price validation
	{
		pOut->PrintMessage("New CardEleven: Enter its price value: ");
		price = pIn->GetInteger(pOut);
	}


	while (rent <= 0)                              //rent validations
	{
		pOut->PrintMessage("New CardEleven: Enter its rent value: ");
		rent = pIn->GetInteger(pOut);
	}

	pOut->ClearStatusBar();

}

void CardEleven::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}

bool CardEleven::IsBought()
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

Player* CardEleven::buy(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = NULL;
	Output* pOut = NULL;

	pIn = pGrid->GetInput();
	pOut = pGrid->GetOutput();

	Player* p = pGrid->GetCurrentPlayer();                     //Gets the current player.
	bool b = IsBought();
	if (b == false)                                            //checks if no player owns the card.
	{
		pOut->PrintMessage("Do you want to buy this card? (Y/N)");
		string a = pIn->GetString(pOut);

		if (a == "Y" || a == "y")
		{
			if (p->GetWallet() < price)
			{
				pOut->PrintMessage("Invalid, No enough amount in wallet");
			}
			else
			{
				p->SetWallet(p->GetWallet() - price);          // deduct card price from the buying player
				SetOwner(p);                                      //setOwner
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

void CardEleven::pay(Grid* pGrid, Player* pPlayer)
{
	bool b = IsBought();
	Player* p = pGrid->GetCurrentPlayer();
	if (b == true)                                                      //checks if the current card had an owner
	{
		if (!(Owner == p))                                           //Checks if the owner is not the current player
		{
			int w = p->GetWallet();                          //Gets the amount in the wallet of the current player
			w -= rent;                                      //decrements the rent value
			p->SetWallet(w);
			int ww = Owner->GetWallet();
			ww += rent;                                //increment the owners' walet by the rent.
			Owner->SetWallet(ww);

		}
	}

}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	buy(pGrid, pPlayer);
	pay(pGrid, pPlayer);
}

void CardEleven::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << ' ' << price << ' ' << rent << endl;
}

bool CardEleven::Load(ifstream& InFile)
{
	Card::Load(InFile);
	InFile >> price >> rent;
	return true;
}

CardEleven::~CardEleven()
{
}

