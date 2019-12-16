#include "LoadGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

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


}
