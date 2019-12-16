#include "CardNine.h"



CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid * pGrid) 
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Choose a cell: ");
	cellpos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}
void CardNine:: Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, cellpos);
	pGrid->UpdateInterface();
}

CardNine::~CardNine()
{
	//  Virtual void destructor
}
