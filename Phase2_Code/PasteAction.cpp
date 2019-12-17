#include "PasteAction.h"
#include "Card.h"



PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->GetOutput()->PrintMessage("Click on the destination cell.");

	CellPosition pastedCardPosition;
	pastedCardPosition = pIn->GetCellClicked();

	Cell* clickedCell = pGrid->GetCurrentCell(pastedCardPosition);
	Card *clipboardCard = pGrid->GetClipboard();
	clipboardCard->SetPosition(pastedCardPosition);
	pastedCard = clipboardCard;
	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	
	ReadActionParameters();


	
	bool z = pGrid->AddObjectToCell(pastedCard);
	if (!z)
		pGrid->PrintErrorMessage("This cell has a game object!");
	Output * pOut = pGrid->GetOutput();
	pOut->ClearStatusBar();
}





PasteAction::~PasteAction()
{
}
