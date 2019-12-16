#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "EditCardAction.h"
#include "RollDiceAction.h"
#include "AddSnakeAction.h"
#include "ToPlayModeAction.h"
#include "ToDesignModeAction.h"
#include "DeleteGameObjectAction.h"
#include "InputDiceValueAction.h"
#include "NewGameAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case EDIT_CARD:
		pAct = new EditCardAction(this);
		break;

	case DELETE_GAME_OBJECT:
		pAct = new DeleteGameObjectAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		pAct = new ToPlayModeAction(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new ToDesignModeAction(this);
		break;

	case INPUT_DICE_VALUE:
		pAct = new InputDiceValueAction(this);
		break;

	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
