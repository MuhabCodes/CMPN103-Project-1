#pragma once
#include "GameObject.h"

class Snake : public GameObject
{

	CellPosition endCellPos; // Snake's end cell position

public:

	// Constructor to initialize snake 

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos);

	// Draw a snake from start to end

	virtual void Draw(Output* pOut) const;

	// Apply Snake action by moving a player from head of snake to the tail (snake end cell)

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	// getter for endCellPos

	CellPosition GetEndPosition() const;

	//Snake IsOverlapping()
	
	virtual bool IsOverlapping(GameObject* newObj) const;

	virtual void Save(ofstream& OutFile, GameObjectType Type);
	
	//virtual void Load(ifstream& InFile);

	// Virtual Destructor 

	virtual ~Snake();
};

