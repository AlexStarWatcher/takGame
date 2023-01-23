#include "board.h"

class board {
	
	sqr* gameBoard;
public:

	board() {
		if (!utils::boardInstenceCounter)cleanSlate();

		sqr* gameBoard = new sqr[utils::boardEdgeSize * utils::boardEdgeSize];
		utils::boardInstenceCounter = false;
	};
	void setSize() { utils::boardEdgeSize = IputLogInt("please choose a board size"); }

private:
	void cleanSlate() { utils::boardInstenceCounter = true; delete[] gameBoard; } //TODO check if 2# instanc give error

public:
	void placePiece(piece* newPiece, int location)
	{
		if (!gameBoard[location].basePtrStatus())
		{
			logger("cannot place new piece at a used location");
			return;
		}
		gameBoard[location].addstack(1,newPiece);
		return;
	}

	void moveStack(int MovingStackSize, int startLocation, int destenyLocation) {

		if (MovingStackSize > utils::boardEdgeSize) { logger("stack to high"); return; }

		//the next 2 lines check if the player is attempting to move from one edge of the board to the other while moving only one index in the array
		//I will try to fined a simpler and clearer way to do that but for now this is my best.
		//if I fined a way to prevent an illigal move from being attempted in the grafic side this will be removed.

		int delta = abs(startLocation - destenyLocation);
		bool isAcrossBoard = ((startLocation + destenyLocation) % utils::boardEdgeSize==1) && (delta==1);
		if (isAcrossBoard || ((delta != 1) && (delta != utils::boardEdgeSize)))
		{
			logger("action not allawed");
			return;
		}

		piece* temp = gameBoard[startLocation].cutStack(MovingStackSize);
		gameBoard[destenyLocation].addstack(MovingStackSize,temp);
	}
	void printSqr(int locationToPrint)
	{
		logger("this is what sqr number ", locationToPrint);
		logger("\n [ ");
		gameBoard[locationToPrint].printSqr();
		logger(" ]\n");
	}

	void printBoard()
	{

		for (int i = 0; i < (utils::boardEdgeSize* utils::boardEdgeSize); i++)
		{
			this->printSqr(i);
		}
	}
};