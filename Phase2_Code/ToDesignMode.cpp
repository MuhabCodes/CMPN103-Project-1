#include "ToDesignMode.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"

ToDesignMode::ToDesignMode(ApplicationManager* pApp) : Action(pApp) {} // initializing the action base class

ToDesignMode::~ToDesignMode() {} // no need for handling anything before destructing

void ToDesignMode::ReadActionParameters() {} // no parameters required

void ToDesignMode::Execute() // create the design mode tool bar
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}
