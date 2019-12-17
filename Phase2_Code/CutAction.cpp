#include "CutAction.h"

#include"Grid.h"
#include"Card.h"


CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{
	
}

void CutAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the source cell.");
	CellPosition cuttedCardPosition;
	cuttedCardPosition = pIn->GetCellClicked();

	Cell* pCell = pGrid->GetCurrentCell(cuttedCardPosition);
	Card* pCard = pCell->HasCard();
	if (pCard != NULL) {
		
		cuttedCard = pCard;
		pGrid->RemoveObjectFromCell(cuttedCardPosition);
	}
	else
		return;

}

void CutAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetClipboard(cuttedCard);
}

CutAction::~CutAction()
{
}
