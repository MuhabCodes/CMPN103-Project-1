#include "CardNine.h"

CellPosition CardNine::cellpos = CellPosition(1);
bool CardNine::initiated = false;

CardNine::CardNine(const CellPosition& pos) : Card(pos)
{
	cardNumber = 9;
	initial = false;
}

void CardNine::ReadCardParameters(Grid * pGrid) 
{
	if (!initiated)
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("New CardNine: Click on its destination cell ... ");
		cellpos = pIn->GetCellClicked();
		initiated = true;
		initial = true;
		pOut->ClearStatusBar();
	}
}
void CardNine:: Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, cellpos);
	pGrid->UpdateInterface();
}

void CardNine::Save(ofstream& OutFile, GameObjectType Type)
{
	Card::Save(OutFile, Type);
	if (Type != CARD)
	{
		return;
	}
	OutFile << ' ' << cellpos.GetCellNum() << endl;
}

bool CardNine::Load(ifstream& InFile)
{
	Card::Load(InFile);
	int cellnum;
	InFile >> cellnum;
	cellpos = CellPosition(cellnum);
	return true;
}

CardNine::~CardNine()
{
	//  Virtual void destructor
}
