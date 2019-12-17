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

void Ladder::Save(ofstream& OutFile, GameObjectType Type)
{
	if (Type != LADDER)
	{
		return;
	}
	OutFile << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << endl;
}

bool Ladder::Load(ifstream& InFile)
{
	int startCell, endCell;
	InFile >> startCell >> endCell;

	if (startCell < 1 || startCell > NumVerticalCells* NumHorizontalCells)
	{
		return false;
	}
	if (endCell < 1 || endCell > NumVerticalCells* NumHorizontalCells)
	{
		return false;
	}

	CellPosition startPos = CellPosition(startCell), endPos = CellPosition(endCell);

	if (startPos.VCell() <= endPos.VCell())
	{
		return false;
	}
	if (startPos.HCell() != endPos.HCell())
	{
		return false;
	}

	position = startPos;
	endCellPos = endPos;
	return true;
}

Ladder::~Ladder()
{
}
