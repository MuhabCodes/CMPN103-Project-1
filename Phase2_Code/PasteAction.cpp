#include "PasteAction.h"
#include "Card.h"



PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	int x, y;
	pGrid->GetOutput()->PrintMessage("Click on the destination cell.");
	Cell clickedCell(pGrid->GetInput()->GetCellClicked());
	Card *clipboardCard = pGrid->GetClipboard();
	
	bool z = pGrid->AddObjectToCell(clipboardCard);
	if (!z)
		pGrid->PrintErrorMessage("This cell has a game object!");
	pOut->ClearStatusBar();
}





PasteAction::~PasteAction()
{
}
