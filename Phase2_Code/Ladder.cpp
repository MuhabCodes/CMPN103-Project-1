#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (!(startCellPos.HCell() != endCellPos.HCell() || startCellPos.VCell() <= endCellPos.VCell()))
	{
		this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = NULL;
	pOut = pGrid->GetOutput(); // Output pointer to print message
	Input* pIn = NULL;
	pIn = pGrid->GetInput(); // Input pointer to wait mouseclick
	int x, y; // 2 variables to enter as arguments for wait mouseclick function

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
	pOut->PrintMessage("You have reached a ladder. Click to continue ... ");
	pIn->GetPointClicked(x, y);

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	// The above is a grid function which updates the player cell to the end cell position assigned to the ladder
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* newLadder = dynamic_cast<Ladder*>(newObj);
	if (newLadder)
	{
		CellPosition newPos = newLadder->GetPosition();
		CellPosition newEndPos = newLadder->GetEndPosition();
		if (newPos.HCell() != position.HCell())
		{
			return false;
		}
		if (position.VCell() > newPos.VCell())
		{
			return (endCellPos.VCell() < newPos.VCell());
		}
		else
		{
			return (position.VCell() > newEndPos.VCell());
		}
	}
	return false;
}

Ladder::~Ladder()
{
}
