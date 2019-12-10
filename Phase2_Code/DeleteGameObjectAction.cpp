#include "DeleteGameObjectAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp) {}

DeleteGameObjectAction::~DeleteGameObjectAction() {}

void DeleteGameObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Delete Object: Click on its Cell ...");
	objPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(objPos);
}
