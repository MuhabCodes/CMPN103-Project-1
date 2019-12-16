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
	CellPosition cardCellPos;
	cardCellPos = pIn->GetCellClicked();
	Cell cell(cardCellPos);
	if (cell.HasCard()) {
		Card* card = cell.HasCard();

		cardCellPos = card->GetPosition();
		card->GetCardNumber();

		cuttedCard = card;
		pGrid->RemoveObjectFromCell(cardCellPos);
	}
	else
		return;

}

void CutAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid;
	pGrid->SetClipboard(cuttedCard);
}

CutAction::~CutAction()
{
}
