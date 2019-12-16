#include "SaveGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) {}

SaveGridAction::~SaveGridAction() {}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Save Grid: Enter file name:");
	FileName = pIn->GetString(pOut);
	
	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	
	Grid* pGrid = pManager->GetGrid();

	ofstream OutFile(FileName, ios::out);
	if (!OutFile.is_open())
	{
		pGrid->PrintErrorMessage("Error: Can't open file ! Click to continue ...");
		return;
	}

	OutFile << pGrid->GetNumberOfLadders() << endl;
	pGrid->SaveAll(OutFile, LADDER);
	OutFile << pGrid->GetNumberOfSnakes() << endl;
	pGrid->SaveAll(OutFile, SNAKE);
	OutFile << pGrid->GetNumberOfCards() << endl;
	pGrid->SaveAll(OutFile, CARD);

	OutFile.close();
}
