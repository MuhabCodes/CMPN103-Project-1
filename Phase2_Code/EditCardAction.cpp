#include "EditCardAction.h"


#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardTen.h"



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
	
	ReadActionParameters();


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
		/*case 11:
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
			break;*/
	default:
		break;
		

	}

	if (pCard)
	{

		/*Cell c(cell);
		Card* p = NULL;
		p = c.HasCard();
		oldCardNumber = p->GetCardNumber();*/

		bool b = pGrid->AddObjectToCell(pCard);
		
			if (b==false)
			{
				pCard->ReadCardParameters(pGrid);
				pGrid->RemoveObjectFromCell(cell);
				pGrid->AddObjectToCell(pCard);
			}
			else
			{
				pGrid->PrintErrorMessage("Invalid, No card in this cell,Click to continue...");
				pGrid->RemoveObjectFromCell(cell);
			}

	}

	
}