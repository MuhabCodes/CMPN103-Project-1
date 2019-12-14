#include "EditCardAction.h"


#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
//#include "CardThree.h"
//#Include "CardFour.h"
//#Include "CardFive.h"
//#Include "CardSix.h"
//#Include "CardSeven.h"
//#Include "CardEight.h"
//#Include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"


EditCardAction::EditCardAction(ApplicationManager* pApp): Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{

}

void EditCardAction::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	Output* pOut = NULL;
	pOut = pGrid->GetOutput();

	pOut->PrintMessage("Click the Card you want to edit");
	cell= pIn->GetCellClicked();

	pOut->PrintMessage("Enter new card number:");
	newCardNumber=pIn->GetInteger(pOut);

	pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{
	Grid* pGrid = NULL;
	pGrid = pManager->GetGrid();
	
	// 1- The first line of any Action Execution is to read its parameter first

	ReadActionParameters();

	// 2- Switch case on cardNumber data member and create the appropriate card object type

	Card* pCard = NULL; // will point to the card object type
	switch (newCardNumber)
	{
	case 1:
		pCard = new CardOne(cell);
		break;
	case 2:
		pCard = new CardTwo(cell);
		break;
		/*
		case 3:
			pCard = new CardThree(cell);
			break;
		case 4:
			pCard = new CardFour(cell);
			break;
		case 5:
			pCard = new CardFive(cell);
			break;
		case 6:
			pCard = new CardSix(cell);
			break;
		case 7:
			pCard = new CardSeven(cell);
			break;
		case 8:
			pCard = new CardEight(cell);
			break;
		case 9:
			pCard = new CardNine(cell);
			break;*/
	case 10:
		pCard = new CardTen(cell);
		break;
	case 11:
		pCard = new CardEleven(cell);
		break;
	case 12:
		pCard = new CardTwelve(cell);
		break;
	case 13:
		pCard = new CardThirteen(cell);
		break;
	case 14:
		pCard = new CardFourteen(cell);
		break;
	default:
		break;
		

	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)

	if (pCard)
	{

		bool b = pGrid->AddObjectToCell(pCard);           // Adds a GameObject to the Cell of its "position" data member
	                                                     // only if the Cell does NOT already contain an object, 
	                                                    // otherwise return false and don't add
	
			if (b == false)                               //if cell contains an object.
			{

				pCard->ReadCardParameters(pGrid);           	// Make the "pCard" reads its card parameters: ReadCardParameters()

				pGrid->RemoveObjectFromCell(cell);             // Removes the GameObject of the Cell of the passed "position"     

				pGrid->AddObjectToCell(pCard);                //Draw the new card
			}
			else
			{
				pGrid->PrintErrorMessage("Invalid, No card in this cell,Click to continue...");
				pGrid->RemoveObjectFromCell(cell);
			}
	}

}