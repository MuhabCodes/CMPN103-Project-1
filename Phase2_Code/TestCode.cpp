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
	pOut->DrawLadder(start_1,end_99);
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
	int ret = pIn->GetInteger(pOut);
	// 2- Print it in the status bar in this format:   You Entered: 116
	//    (assuming the entered number is 116)
	pOut->PrintMessage("You entered: ");
	pOut->PrintMessage(to_string(ret));
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
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));
	// 3- Repeat Step 1 and 2 five times
	ClickedCell = pIn->GetCellClicked();
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));
	ClickedCell = pIn->GetCellClicked();
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));
	ClickedCell = pIn->GetCellClicked();
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));
	ClickedCell = pIn->GetCellClicked();
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));
	ClickedCell = pIn->GetCellClicked();
	pOut->PrintMessage(to_string(ClickedCell.VCell()));
	pOut->PrintMessage(to_string(ClickedCell.HCell()));

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar

	string s=pIn->GetSrting(pOut);

	// 2- After reading the string clear the status bar
	
	pOut->ClearStatusBar();
	
	// 3- print on the status bar "You Entered" then print the string
	
	pOut->PrintMessage("You Entered");
	pOut->PrintMessage(s);
	pIn->GetSrting(pOut);
	
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
	int n = pIn->GetInteger(pOut);
	// 2- Call SetVCell() of cellpos_1 with that integer
	cellpos_1.SetVCell(n);
	// 3- Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5)
	int v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	// 4- Call GetPointClicked()
	pIn->GetPointClicked(x,y);
	// 5- Repeat the above steps FIVE TIMES

	n = pIn->GetInteger(pOut);
	cellpos_1.SetVCell(n);
	v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	pIn->GetPointClicked(x, y); 
	
	n = pIn->GetInteger(pOut);
	cellpos_1.SetVCell(n);
	v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	pIn->GetPointClicked(x, y);

	n = pIn->GetInteger(pOut);
	cellpos_1.SetVCell(n);
	v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	pIn->GetPointClicked(x, y);

	n = pIn->GetInteger(pOut);
	cellpos_1.SetVCell(n);
	v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	pIn->GetPointClicked(x, y);

	n = pIn->GetInteger(pOut);
	cellpos_1.SetVCell(n);
	v = cellpos_1.VCell();
	pOut->PrintMessage("Now the vCell =");
	pOut->PrintMessage(to_string(v));
	pIn->GetPointClicked(x, y);

	// 6- Repeat all the above steps to test SetHCell() function instead with the needed modifications

	int m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	int h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y); 
	
        m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y);

	m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y);

	m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y);

	m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y);

	m = pIn->GetInteger(pOut);
	cellpos_1.SetHCell(m);
	h = cellpos_1.HCell();
	pOut->PrintMessage("Now the HCell =");
	pOut->PrintMessage(to_string(h));
	pIn->GetPointClicked(x, y);


	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell
	int vc = pIn->GetInteger(pOut);
	int hc = pIn->GetInteger(pOut);
	// 2- Creates a CellPosition object of them
	CellPosition obj1(vc,hc);
	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it)
	int r = obj1.GetCellNum();
	// 4- Print the Cell Number on the status bar
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));
	// 5- Repeat the above steps Five TIMES

	vc = pIn->GetInteger(pOut);
	hc = pIn->GetInteger(pOut);
	obj1.SetVCell(vc);
	obj1.SetHCell(hc);
	r = obj1.GetCellNum();
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));

	vc = pIn->GetInteger(pOut);
	hc = pIn->GetInteger(pOut);
	obj1.SetVCell(vc);
	obj1.SetHCell(hc);
	r = obj1.GetCellNum();
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));

	vc = pIn->GetInteger(pOut);
	hc = pIn->GetInteger(pOut);
	obj1.SetVCell(vc);
	obj1.SetHCell(hc);
	r = obj1.GetCellNum();
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));

	vc = pIn->GetInteger(pOut);
	hc = pIn->GetInteger(pOut);
	obj1.SetVCell(vc);
	obj1.SetHCell(hc);
	r = obj1.GetCellNum();
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));


	vc = pIn->GetInteger(pOut);
	hc = pIn->GetInteger(pOut);
	obj1.SetVCell(vc);
	obj1.SetHCell(hc);
	r = obj1.GetCellNum();
	pOut->PrintMessage("Cell Number:");
	pOut->PrintMessage(to_string(obj1.GetCellNum()));

	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user one integer representing cellNum
	int cell_num = pIn->GetInteger(pOut);
	// 2- Creates a CellPosition object of that integer using that constructor: CellPosition (int cellNum);
	CellPosition OBJ(cell_num);
	//   --> it uses the function : GetCellPositionFromNum () inside it
	// 4- Print the Cell vCell and hCell on the status bar
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ.HCell()));
	// 5- Repeat the above steps Five TIMES

	int cell_num1 = pIn->GetInteger(pOut);
	CellPosition OBJ1(cell_num1);
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ1.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ1.HCell()));

	int cell_num2 = pIn->GetInteger(pOut);
	CellPosition OBJ2(cell_num2);
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ2.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ2.HCell()));

	int cell_num3 = pIn->GetInteger(pOut);
	CellPosition OBJ3(cell_num3);
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ3.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ3.HCell()));

	int cell_num4 = pIn->GetInteger(pOut);
	CellPosition OBJ4(cell_num4);
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ4.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ4.HCell()));

	int cell_num5 = pIn->GetInteger(pOut);
	CellPosition OBJ5(cell_num5);
	pOut->PrintMessage("Vcell:");
	pOut->PrintMessage(to_string(OBJ5.VCell()));
	pOut->PrintMessage("Hcell:");
	pOut->PrintMessage(to_string(OBJ5.HCell()));


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
			pOut->CreatePlayModeToolBar();
			break;


			///TODO:  ADD Cases similarly for ALL the remaining actions of DESIGN Mode


		case ROLL_DICE:
			pOut->PrintMessage("Action: ROLL_DICE , Click anywhere");
			break;

		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
			pOut->CreateDesignModeToolBar();
			break;

			///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode

		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


