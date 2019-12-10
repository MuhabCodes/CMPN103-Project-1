#include "ToDesignModeAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp) {} // initializing the action base class

ToDesignModeAction::~ToDesignModeAction() {} // no need for handling anything before destructing

void ToDesignModeAction::ReadActionParameters() {} // no parameters required

void ToDesignModeAction::Execute() // create the design mode tool bar
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}
