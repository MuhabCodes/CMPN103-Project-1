#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (!(startCellPos.HCell() != endCellPos.HCell() || startCellPos.VCell() >= endCellPos.VCell()))
	{
		this->endCellPos = endCellPos;
	}
	// Snake Validation 
}

void Snake::Draw(Output* pOut) const
{
	// Function to draw snake

	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	// Output and Window pointer declaration to print message and wait for user click

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();
	Input* pIn = NULL;
	pIn = pGrid->GetInput();

	// Declare 2 variables to enter as arguments for GetPointClicked function

	int x, y;

	// Print a message for the user that they've reached a Snake

	pOut->PrintMessage("You have reached a Snake, Click anywhere to continue ... ");

	// wait for mouseclick from user 

	pIn->GetPointClicked(x, y);

	// Updates Player location to assign it to the new location to apply the effect of Snake

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	// getter for endCellPos
	return endCellPos;
}

bool Snake::IsOverlapping(GameObject* newObj) const
{
	Snake* newSnake = dynamic_cast<Snake*>(newObj);
	if (newSnake)
	{
		CellPosition newPos = newSnake->GetPosition();
		CellPosition newEndPos = newSnake->GetEndPosition();
		if (newPos.HCell() != position.HCell())
		{
			return false;
		}
		if (position.VCell() < newPos.VCell())
		{
			return (endCellPos.VCell() > newPos.VCell());
		}
		else
		{
			return (position.VCell() < newEndPos.VCell());
		}
	}
	return false;
}

void Snake::Save(ofstream& OutFile, GameObjectType Type)
{
	if (Type != SNAKE)
	{
		return;
	}
	OutFile << position.GetCellNum() << ' ' << endCellPos.GetCellNum() << endl;
}

bool Snake::Load(ifstream& InFile)
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

	if (startPos.VCell() >= endPos.VCell())
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

Snake::~Snake()
{
	// Virtual Snake Destructor
}
