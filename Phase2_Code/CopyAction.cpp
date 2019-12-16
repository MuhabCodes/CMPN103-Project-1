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
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the source cell.");
	copiedCardPosition = pIn->GetCellClicked();
	Cell c(copiedCardPosition);
	if (c.HasCard()) {
		
		Card copiedCard(copiedCardPosition);
		copiedCardNumber = copiedCard.GetCardNumber();
	}
	else
		return;

	pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
	ReadActionParameters();
	
	pCard->SetCardNumber(copiedCardNumber);
	pGrid->SetClipboard(pCard);
}

CopyAction::~CopyAction()
{
}
