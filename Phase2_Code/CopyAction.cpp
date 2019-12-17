#include "CopyAction.h"
#include "Card.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"



CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the source cell.");
	CellPosition copiedCardPosition;
	copiedCardPosition = pIn->GetCellClicked();
	
	Cell* pCell = pGrid->GetCurrentCell(copiedCardPosition);
	Card* pCard = pCell->HasCard();
	if (pCard != NULL) {
		
		
		copiedCardPosition = pCard->GetPosition();
		pCard->GetCardNumber();

		copiedCard = pCard;
	}
	else
		return;

	pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
	ReadActionParameters();
	
	pGrid->SetClipboard(copiedCard);
}

CopyAction::~CopyAction()
{
}
