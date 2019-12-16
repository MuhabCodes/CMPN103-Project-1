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
	Grid * pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the source cell.");
	CellPosition copiedCardPosition;
	copiedCardPosition = pIn->GetCellClicked();
	Cell cell(copiedCardPosition);
	
	if (cell.HasCard()) {
		
		Card* card = cell.HasCard();

		copiedCardPosition = card->GetPosition();
		card->GetCardNumber();

		copiedCard = card;
	}
	else
		return;

	pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid; 

	pGrid->SetClipboard(copiedCard);
}

CopyAction::~CopyAction()
{
}
