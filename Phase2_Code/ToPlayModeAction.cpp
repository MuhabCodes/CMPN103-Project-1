#include "ToPlayModeAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) : Action(pApp) {} // initializing the action base clase

ToPlayModeAction::~ToPlayModeAction() {} // no need for handling anything before destructing

void ToPlayModeAction::ReadActionParameters() {} // no parameters required

void ToPlayModeAction::Execute() // create the player mode tool bar
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
}
