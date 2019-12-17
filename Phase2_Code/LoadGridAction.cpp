#include "LoadGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp) {}

LoadGridAction::~LoadGridAction() {}

void LoadGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Load Grid: Enter file name:");
	FileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void LoadGridAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	ifstream InFile(FileName, ios::in);
	if (!InFile.is_open())
	{
		pGrid->PrintErrorMessage("Error: Can't open file ! Click to continue ...");
		return;
	}

	pGrid->ClearGrid();

	int LadderCount, SnakeCount, CardCount;

	InFile >> LadderCount;
	for (int i = 0; i < LadderCount; ++i)
	{
		Ladder* pLadder = new Ladder(CellPosition(0), CellPosition(0));
		if (!pLadder->Load(InFile))
		{
			delete pLadder;
			continue;
		}

		CellPosition startPos = pLadder->GetPosition();
		CellPosition endPos = pLadder->GetEndPosition();

		if (pGrid->GetGameObject(startPos))
		{
			delete pLadder;
			continue;
		}
		if (pGrid->HasEnd(startPos))
		{
			delete pLadder;
			continue;
		}
		if (pGrid->GetGameObject(endPos))
		{
			delete pLadder;
			continue;
		}

		bool added = pGrid->AddObjectToCell(pLadder);
		if (added)
		{
			pGrid->SetEnd(endPos, true);
		}
		else
		{
			delete pLadder;
		}
	}

	InFile >> SnakeCount;
	for (int i = 0; i < SnakeCount; ++i)
	{
		Snake* pSnake = new Snake(CellPosition(0), CellPosition(0));
		if (!pSnake->Load(InFile))
		{
			delete pSnake;
			continue;
		}

		CellPosition startPos = pSnake->GetPosition();
		CellPosition endPos = pSnake->GetEndPosition();

		if (pGrid->GetGameObject(startPos))
		{
			delete pSnake;
			continue;
		}
		if (pGrid->HasEnd(startPos))
		{
			delete pSnake;
			continue;
		}
		if (pGrid->GetGameObject(endPos))
		{
			delete pSnake;
			continue;
		}

		bool added = pGrid->AddObjectToCell(pSnake);
		if (added)
		{
			pGrid->SetEnd(endPos, true);
		}
		else
		{
			delete pSnake;
		}
	}

	InFile >> CardCount;
	for (int i = 0; i < CardCount; ++i)
	{
		int cardNum;
		Card* pCard = NULL;

		InFile >> cardNum;
		switch (cardNum)
		{
		case 1:
			pCard = new CardOne(CellPosition(0));
			break;
		case 2:
			pCard = new CardTwo(CellPosition(0));
			break;
		case 3:
			pCard = new CardThree(CellPosition(0));
			break;
		case 4:
			pCard = new CardFour(CellPosition(0));
			break;
		case 5:
			pCard = new CardFive(CellPosition(0));
			break;
		case 6:
			pCard = new CardSix(CellPosition(0));
			break;
		case 7:
			pCard = new CardSeven(CellPosition(0));
			break;
		case 8:
			pCard = new CardEight(CellPosition(0));
			break;
		case 9:
			pCard = new CardNine(CellPosition(0));
			break;
		case 10:
			pCard = new CardTen(CellPosition(0));
			break;
		case 11:
			pCard = new CardEleven(CellPosition(0));
			break;
		case 12:
			pCard = new CardTwelve(CellPosition(0));
			break;
		case 13:
			pCard = new CardThirteen(CellPosition(0));
			break;
		case 14:
			pCard = new CardFourteen(CellPosition(0));
			break;
		default:
			break;
		}
		
		if (pCard == NULL)
		{
			continue;
		}

		if (!pCard->Load(InFile))
		{
			delete pCard;
			continue;
		}

		if (pGrid->GetGameObject(pCard->GetPosition()))
		{
			delete pCard;
			continue;
		}

		bool added = pGrid->AddObjectToCell(pCard);
		if (!added)
		{
			delete pCard;
		}
	}
}
