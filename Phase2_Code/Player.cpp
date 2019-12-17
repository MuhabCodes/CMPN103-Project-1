#include "Player.h"

#include "GameObject.h"
#include "Card.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	IsPrevented = false;
	OnFire = 0;
	IsPoisoned = 0;
	AnotherDiceRoll = false;
	attackCount = 0;
	attacksDone[0] = false;
	attacksDone[1] = false;
	attacksDone[2] = false;
	attacksDone[3] = false;
	attacksDone[4] = false;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	// Wallet Amount can't be negative - Muhab

	if (wallet < 0)
	{
		this->wallet = 0;
		return;
	}

	this->wallet = wallet;
	// Make any needed validations

}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetTurnCount(int turnCount)
{
	this->turnCount = turnCount;
}


int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetStepCount(int stepCount)
{
	this->stepCount = stepCount;
}

int Player::GetStepCount() const
{
	return stepCount;
}

int Player::GetDiceNum() const
{
	return justRolledDiceNum;
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

void Player::SetAnotherDiceRoll(bool AnotherDiceRoll)
{
	this->AnotherDiceRoll = AnotherDiceRoll;
}

void Player::SetIsPrevented(bool IsPrevented)
{
	this->IsPrevented = IsPrevented;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	turnCount++; // turnCounter incrementer

	//turnCount reset and wallet incrementer

	if (OnFire--)
	{
		SetWallet(wallet - 20);
	}
	
	if (IsPrevented)
	{
		IsPrevented = false;
		return;
	}

	if (IsPoisoned--)
	{
		--diceNumber;
	}

	if (GetTurnCount() == 3)
	{
		turnCount = 0;
		if (attackCount < 2)
		{
			Input* pIn = pGrid->GetInput();
			Output* pOut = pGrid->GetOutput();
			pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? [Y/N]");
			string response = pIn->GetString(pOut);
			while ((response.length() != 1) || (response != "n" && response != "N" && response != "y" && response != "Y"))
			{
				pOut->PrintMessage("Error: Invalid response ! Please enter 'Y' or 'N' :");
				response = pIn->GetString(pOut);
			}
			if (response == "n" || response == "N")
			{
				SetWallet(GetWallet() + diceNumber * 10);
				justRolledDiceNum = diceNumber;
				pOut->ClearStatusBar();
				return;
			}
			else
			{
				++attackCount;
				pOut->PrintMessage("Enter '1' for Ice, '2' for Fire, '3' for Poison, or '4' for Lightning: ");
				int attack = pIn->GetInteger(pOut);
				while (true)
				{
					if (attack < 1 || attack > 4)
					{
						pOut->PrintMessage("Error: Invalid response ! Please enter '1' for Ice, '2' for Fire, '3' for Poison, or '4' for Lightning:");
						attack = pIn->GetInteger(pOut);
						continue;
					}
					if (attacksDone[attack])
					{
						pOut->PrintMessage("You already used this attack ! Please choose another attack:");
						attack = pIn->GetInteger(pOut);
						continue;
					}
					break;
				}
				int P;
				switch (attack)
				{
				case 1:
					pOut->PrintMessage("Choose a player to prevent from rolling the next turn:");
					P = pIn->GetInteger(pOut);
					while (true)
					{
						if (P < 0 || P >= MaxPlayerCount)
						{
							pOut->PrintMessage("Error: Invalid choice ! Please choose a player to prevent from rolling the next turn:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						if (P == playerNum)
						{
							pOut->PrintMessage("You can't choose yourself ! Please choose another a player to prevent from rolling the next turn:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						if (pGrid->GetPlayer(P)->IsPrevented)
						{
							pOut->PrintMessage("This player is already prevented from rolling the next turn ! Please choose another player:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						break;
					}
					pGrid->GetPlayer(P)->SetIsPrevented(true);
					attacksDone[attack] = true;
					break;
				case 2:
					pOut->PrintMessage("Choose a player to set on fire:");
					P = pIn->GetInteger(pOut);
					while (true)
					{
						if (P < 0 || P >= MaxPlayerCount)
						{
							pOut->PrintMessage("Error: Invalid choice ! Please choose a player to set on fire:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						if (P == playerNum)
						{
							pOut->PrintMessage("You can't choose yourself ! Please choose another player to set on fire:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						break;
					}
					pGrid->GetPlayer(P)->OnFire = 3;
					attacksDone[attack] = true;
					break;
				case 3:
					pOut->PrintMessage("Choose a player to poison:");
					P = pIn->GetInteger(pOut);
					while (true)
					{
						if (P < 0 || P >= MaxPlayerCount)
						{
							pOut->PrintMessage("Error: Invalid choice ! Please choose a player to poison:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						if (P == playerNum)
						{
							pOut->PrintMessage("You can't choose yourself ! Please choose another player to poison:");
							P = pIn->GetInteger(pOut);
							continue;
						}
						break;
					}
					pGrid->GetPlayer(P)->IsPoisoned = 5;
					attacksDone[attack] = true;
					break;
				case 4:
					for (int i = 0; i < MaxPlayerCount; ++i)
					{
						if (i != playerNum)
						{
							Player* pP = pGrid->GetPlayer(i);
							pP->SetWallet(pP->wallet - 20);
						}
					}
					attacksDone[attack] = true;
					break;
				default:
					break;
				}
				pGrid->PrintErrorMessage("Special attack applied ! Click to continue ...");
			}
		}
		SetWallet(GetWallet() + diceNumber * 10);
		justRolledDiceNum = diceNumber;
		return;
	}


	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	CellPosition Pos = pCell->GetCellPosition();

	if (wallet > 0)
	{
		do
		{
			Pos = pCell->GetCellPosition();

			AnotherDiceRoll = false;

			justRolledDiceNum = diceNumber;
			Pos.AddCellNum(diceNumber);
			stepCount += diceNumber;
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), Pos);
			if (pCell->GetGameObject() != NULL)
			{
				pCell->GetGameObject()->Apply(pGrid, this);
				stepCount = this->GetCell()->GetCellPosition().GetCellNum();
			}
			
			// 6- Apply() the game object of the reached cell (if any)

			// pCell GetGameObject function returns false if there exists a game object
			// so the opposite of GetGameObject means there is a GameObject in said cell
			// therefore we can use it in the implementation of the function 
			// -Muhab



			// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)	

			if ( stepCount >= 99)
			{
				pGrid->SetEndGame(true);
			}
		} while (AnotherDiceRoll);
	}
	else 
	{
		SetWallet(GetWallet() + diceNumber * 10);
		justRolledDiceNum = diceNumber;
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}