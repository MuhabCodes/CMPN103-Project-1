#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

CardTwo::~CardTwo() {}

int CardTwo::walletAmount = 0;

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput(); // Input Pointer using Grid pointer
	Output* pOut = pGrid->GetOutput();  // Output Pointer using Grid pointer
	pOut->PrintMessage("New CardTwo: Enter it's wallet amount: "); // Display Message for user to enter wallet value
	walletAmount = pIn->GetInteger(pOut); // Value of Wallet Amount entered by the user

	// Clear any message 

	pOut->ClearStatusBar();

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{


	// Apply card fn in base class Card

	// Setting the player pointer to the current player to adjust their wallet

	pPlayer = pGrid->GetCurrentPlayer();

	// Setting wallet of current player by adding their current wallet to the entered value to be added by the user

	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);


}