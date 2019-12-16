#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	bool IsPrevented;      //  bool added to prevent player movement in CardEight

	bool AnotherDiceRoll;   // bool added to give player an extra roll for CardSeven

	// Might add similar bools for bonus super attacks;

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for pCell
	Cell* GetCell() const;			// A getter for pCell

	void SetWallet(int wallet);		// A setter for wallet
	int GetWallet() const;			// a getter for wallet

	void SetTurnCount(int turnCount);		// A setter for turnCount
	int GetTurnCount() const;		// A getter for turnCount

	void SetStepCount(int stepCount);		// A setter for stepCount
	int GetstepCount() const;		// A getter for stepCount

	int GetDiceNum() const;

	int GetPlayerNum() const;		// A getter for playerNum

	void SetIsPrevented(bool IsPrevented);		// A setter for IsPrevented

	void SetAnotherDiceRoll(bool AnotherDiceRoll);

	///TODO: You can add setters and getters for data members here (if needed)
	

	
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

};

