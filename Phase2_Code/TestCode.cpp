#include "Input.h"
#include "Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output * pOut = new Output();
	Input * pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	
	//			Create The FULL Tool bar of Design Mode, the grid area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 2.1- Drawing Cells with Cards Test ///
	/// ===================================
	pOut->PrintMessage("2.1- Drawing (Cells with CARDS) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition card_1 (0, 0);  // assume card number is : 1
	CellPosition card_2 (0, 10); // assume card number is : 2
	CellPosition card_3 (8, 0);  // assume card number is : 3
	CellPosition card_4 (8, 10); // assume card number is : 4
	CellPosition card_10 (4, 5); // assume card number is : 10


	///TODO: Call Function DrawCell of Class Ouput Multiple Times
	///       to draw cells in cell locations of: card_1, card_2, ..., card_10 declared above
	///       with cardNum 1, 2, 3, 4 and 10 respectively

	pOut->DrawCell(card_1, 1);
	pOut->DrawCell(card_2, 2);
	pOut->DrawCell(card_3, 3);
	pOut->DrawCell(card_4, 4);
	pOut->DrawCell(card_10, 10);

	pOut->PrintMessage("FINISHED - Drawing (Cells with CARDS) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 2.2- Drawing Players Test ///
	/// ==============================
	pOut->PrintMessage("2.2- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition player_1 (8, 0);
	CellPosition player_15 (2, 18);
	CellPosition player_99 (2, 5);


	///TODO: Call Function DrawPlayer of Class Ouput Multiple Times
	///       to draw the following players:
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) in cell position (player_1 declared above) 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) in cell position (player_1 declared above) 
	///       playerNum (2) with color (PlayerColors[2] defined in UI object) in cell position (player_1 declared above) 
	///       playerNum (3) with color (PlayerColors[3] defined in UI object) in cell position (player_1 declared above) 
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) in cell position (player_15 declared above) 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) in cell position (player_99 declared above) 
	///       playerNum (5) with color (PlayerColors[1] defined in UI object) in cell position (player_99 declared above) 
	///       playerNum (-1) with color (PlayerColors[1] defined in UI object) in cell position (player_99 declared above) 
	///       Note the last two player is (INVALID)

	pOut->DrawPlayer(player_1, 0, UI.PlayerColors[0]);
	pOut->DrawPlayer(player_1, 1, UI.PlayerColors[1]);
	pOut->DrawPlayer(player_1, 2, UI.PlayerColors[2]);
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[3]);
	pOut->DrawPlayer(player_15, 0, UI.PlayerColors[0]);
	pOut->DrawPlayer(player_99, 1, UI.PlayerColors[1]);
	pOut->DrawPlayer(player_99, 5, UI.PlayerColors[1]);
	pOut->DrawPlayer(player_99, -1, UI.PlayerColors[1]);

	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 2.3- Drawing Ladders ///
	/// ====================
	pOut->PrintMessage("2.3- Drawing (Ladders) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition start_1 (0, 0);
	CellPosition end_34 (5, 0);

	CellPosition start_22 (7, 10);
	CellPosition end_99 (0, 10);

	///TODO: Call Function DrawLadder of Class Ouput Multiple Times
	///       to draw the following ladders:
	///       a ladder from start_1 to end_34 declared above
	///       a ladder from start_22 to end_99 declared above
	///       a ladder from start_1 to end_99 declared above (invalid)
	///       a ladder from end_34 to start_1 declared above (invalid)
	
	pOut->DrawLadder(start_1, end_34);
	pOut->DrawLadder(start_22, end_99);

	pOut->DrawLadder(start_1, end_99);
	pOut->DrawLadder(end_34, start_1);

	pOut->PrintMessage("FINISHED - Drawing (Ladders) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 2.4- Drawing Snakes ///
	/// ====================
	pOut->PrintMessage("2.4- Drawing (Snakes) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition start_24 (6, 1);
	CellPosition end_2 (8, 1);

	CellPosition start_98 (0, 9);
	CellPosition end_32 (6, 9);

	///TODO: Call Function DrawSnake of Class Ouput Multiple Times
	///       to draw the following snakes:
	///       a snake from start_24 to end_2 declared above
	///       a snake from start_98 to end_32 declared above
	///       a snake from start_98 to end_2 declared above (invalid)
	///       a snake from end_2 to start_24 declared above (invalid)
	
	pOut->DrawSnake(start_24, end_2);
	pOut->DrawSnake(start_98, end_32);

	pOut->DrawSnake(start_98, end_2);
	pOut->DrawSnake(end_2,start_24);

	pOut->PrintMessage("FINISHED - Drawing (Snakes) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call GetInteger Function and receive its returned integer
	pOut->PrintMessage("Enter an integer:");
	int N = pIn->GetInteger(pOut);

	// 2- Print it in the status bar in this format:   You Entered: 116
	//    (assuming the entered number is 116)
	pOut->PrintMessage("You entered the number: " + to_string(N));

	// 3- Call GetPointClicked() function
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition ClickedCell;
	///TODO: Add code here to 
	// 1- Call function GetCellClicked
	ClickedCell = pIn->GetCellClicked();

	// 2- Print on the status bar the vCell and hCell of the clicked cell
	pOut->PrintMessage("(vCell, hCell) = (" + to_string(ClickedCell.VCell()) + ", " + to_string(ClickedCell.HCell()) + ")");

	// 3- Repeat Step 1 and 2 five times
	for (int i = 0; i < 5; i++)
	{
		ClickedCell = CellPosition();
		ClickedCell = pIn->GetCellClicked();
		pOut->PrintMessage("(vCell, hCell) = (" + to_string(ClickedCell.VCell()) + ", " + to_string(ClickedCell.HCell()) + ")");
	}

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	pOut->PrintMessage("Enter a string:");
	string S = pIn->GetString(pOut);

	// 2- After reading the string clear the status bar
	pOut->ClearStatusBar();
	
	// 3- print on the status bar "You Entered" then print the string
	pOut->PrintMessage("You entered the string: " + S);
	pIn->GetPointClicked(x, y);
	
	// NOTE: GetString() is already implemented. It is just required from you to call it

	pOut->PrintMessage("FINISHED - (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:	
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition cellpos_1(0, 0);

	///TODO:
	// 1- Ask user to enter an integer and read it using GetInteger()
	pOut->PrintMessage("Enter integer for vCell:");
	N = pIn->GetInteger(pOut);

	// 2- Call SetVCell() of cellpos_1 with that integer
	cellpos_1.SetVCell(N);

	// 3- Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5)
	pOut->PrintMessage("Now the vCell = " + to_string(cellpos_1.VCell()) + ", Click to continue");

	// 4- Call GetPointClicked()
	pIn->GetPointClicked(x,y);

	// 5- Repeat the above steps FIVE TIMES
	for (int i = 0; i < 5; i++)
	{
		cellpos_1 = CellPosition(0, 0);
		pOut->PrintMessage("Enter integer for vCell:");
		N = pIn->GetInteger(pOut);
		cellpos_1.SetVCell(N);
		pOut->PrintMessage("Now the vCell = " + to_string(cellpos_1.VCell()) + ", Click to continue");
		pIn->GetPointClicked(x, y);
	}

	// 6- Repeat all the above steps to test SetHCell() function instead with the needed modifications
	CellPosition cellpos_2(0, 0);
	pOut->PrintMessage("Enter integer for hCell:");
	N = pIn->GetInteger(pOut);
	cellpos_2.SetHCell(N);
	pOut->PrintMessage("Now the hCell = " + to_string(cellpos_2.HCell()) + ", Click to continue");
	pIn->GetPointClicked(x, y);

	for (int i = 0; i < 5; i++)
	{
		cellpos_2 = CellPosition(0, 0);
		pOut->PrintMessage("Enter integer for hCell:");
		N = pIn->GetInteger(pOut);
		cellpos_2.SetHCell(N);
		pOut->PrintMessage("Now the hCell = " + to_string(cellpos_2.HCell()) + ", Click to continue");
		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell
	pOut->PrintMessage("Enter integer for vCell:");
	int vc = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter integer for hCell:");
	int hc = pIn->GetInteger(pOut);

	// 2- Creates a CellPosition object of them
	CellPosition cellpos_3(vc,hc);

	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it)
	N = cellpos_3.GetCellNum();

	// 4- Print the Cell Number on the status bar
	pOut->PrintMessage("Cell Number = " + to_string(N) + ", Click to continue");
	pIn->GetPointClicked(x, y);

	// 5- Repeat the above steps Five TIMES
	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter integer for vCell:");
		vc = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter integer for hCell:");
		hc = pIn->GetInteger(pOut);
		cellpos_3 = CellPosition(vc, hc);
		N = cellpos_3.GetCellNum();
		pOut->PrintMessage("Cell Number = " + to_string(N) + ", Click to continue");
		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user one integer representing cellNum
	pOut->PrintMessage("Enter integer for cellNum:");
	N = pIn->GetInteger(pOut);

	// 2- Creates a CellPosition object of that integer using that constructor: CellPosition (int cellNum);
	//   --> it uses the function : GetCellPositionFromNum () inside it
	CellPosition cellpos_4(N);

	// 4- Print the Cell vCell and hCell on the status bar
	pOut->PrintMessage("(vCell, hCell) = (" + to_string(cellpos_4.VCell()) + ", " + to_string(cellpos_4.HCell()) + ")" + ", Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	// 5- Repeat the above steps Five TIMES
	for (int i = 0; i < 5; i++)
	{
		pOut->PrintMessage("Enter integer for cellNum:");
		N = pIn->GetInteger(pOut);
		cellpos_4 = CellPosition(N);
		pOut->PrintMessage("(vCell, hCell) = (" + to_string(cellpos_4.VCell()) + ", " + to_string(cellpos_4.HCell()) + ")" + ", Click to continue");
		pIn->GetPointClicked(x,y);	//Wait for any click
	}

	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5: 
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for EACH action (both Create-Grid mode and Game mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_LADDER:
			pOut->PrintMessage("Action: ADD_LADDER , Click anywhere");
			break;

		case ADD_SNAKE:
			pOut->PrintMessage("Action: ADD_SNAKE , Click anywhere");
			break;

		case ADD_CARD:
			pOut->PrintMessage("Action: ADD_CARD , Click anywhere");
			break;

		case EXIT:				
			break;

		case TO_PLAY_MODE:

			///TODO:  Call Function (PrintPlayersInfo) of Class Output with a string similar to 
			//        the one given in the screenshot of project document

			pOut->PrintMessage("Action: TO_PLAY_MODE , Click anywhere");
			pOut->PrintPlayersInfo("P0(100, 0), P1(100, 0), P2(100, 0), P3(100, 0) | Curr = 0");
			break;


			///TODO:  ADD Cases similarly for ALL the remaining actions of DESIGN Mode

		case COPY_CARD:
			pOut->PrintMessage("Action: COPY_CARD , Click anywhere");
			break;

		case CUT_CARD:
			pOut->PrintMessage("Action: CUT_CARD , Click anywhere");
			break;

		case PASTE_CARD:
			pOut->PrintMessage("Action: PASTE_CARD , Click anywhere");
			break;

		case EDIT_CARD:
			pOut->PrintMessage("Action: EDIT_CARD , Click anywhere");
			break;

		case DELETE_GAME_OBJECT:
			pOut->PrintMessage("Action: DELETE_GAME_OBJECT , Click anywhere");
			break;

		case SAVE_GRID:
			pOut->PrintMessage("Action: SAVE_GRID , Click anywhere");
			break;

		case OPEN_GRID:
			pOut->PrintMessage("Action: OPEN_GRID , Click anywhere");
			break;


		case ROLL_DICE:
			pOut->PrintMessage("Action: ROLL_DICE , Click anywhere");
			break;

		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
			pOut->CreateDesignModeToolBar();
			break;

			///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode

		case INPUT_DICE_VALUE:
			pOut->PrintMessage("Action: INPUT_DICE_VALUE , Click anywhere");
			break;

		case NEW_GAME:
			pOut->PrintMessage("Action: NEW_GAME , Click anywhere");
			break;

		case GRID_AREA:
			pOut->PrintMessage("GRID , Click anywhere");
			break;
		
		case STATUS:
			pOut->PrintMessage("STATUS , Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("EMPTY , Click anywhere");
			break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


