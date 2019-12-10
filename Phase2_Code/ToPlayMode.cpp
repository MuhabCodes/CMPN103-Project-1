#include "ToPlayMode.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

ToPlayMode::ToPlayMode(ApplicationManager* pApp) : Action(pApp) {} // initializing the action base clase

ToPlayMode::~ToPlayMode() {} // no need for handling anything before destructing

void ToPlayMode::ReadActionParameters() {} // no parameters required

void ToPlayMode::Execute() // create the player mode tool bar
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
}
