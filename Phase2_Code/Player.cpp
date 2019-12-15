#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

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
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetstepCount() const
{
	return stepCount;
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
	
	// turnCounter incrementer --Muhab

	turnCount++;

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	//turnCount reset and wallet incrementer -Muhab

	if (GetTurnCount() == 3)
	{
		turnCount = 0;
		SetWallet(GetWallet() + diceNumber * 10);
		justRolledDiceNum = diceNumber;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber

	justRolledDiceNum = diceNumber;

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	CellPosition Pos = pCell->GetCellPosition();
	
	Pos.AddCellNum(diceNumber);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position


	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), Pos);


	// 6- Apply() the game object of the reached cell (if any)

	// pCell GetGameObject function returns false if there exists a game object
	// so the opposite of GetGameObject means there is a GameObject in said cell
	// therefore we can use it in the implementation of the function 
	// -Muhab

	/*if (pCell->GetGameObject() != NULL)
	{
		if (pCell->HasCard())
		{
			Card* card = (Card*)pCell->GetGameObject();
		}
		else if (pCell->HasSnake())
		{
			
			Snake* snake = (Snake*)pCell->GetGameObject();
		}
		else if (pCell->HasLadder())
		{
			Ladder* ladder = (Ladder*)pCell->GetGameObject();
		}
		// fill the last 3 if conditions with your Implementation - Muhab
		
	}*/
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)	
	if (Pos.GetCellNum() > NumHorizontalCells * NumVerticalCells)
	{
		pGrid->SetEndGame(true);
	}
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}