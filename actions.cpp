#include "sqr.h"
#include "piece.h"
#include "logger.h"
#include <cmath>

namespace actions{

	
	static void* board;

	void setSize()	{boardEdge = IputLogInt("please choose a board size");}

	void cleanSlate() { boardInstenceCounter = true; delete[] board; } //TODO check if 2# instanc give error

	bool boardbilder()
	{
		if (!boardInstenceCounter)cleanSlate();

		board = new sqr [boardEdge * boardEdge];
		boardInstenceCounter = false;
		return true;
	}

	bool placePiece(piece* newPiece, int location, void * board[])
	{
		if (board[location] != nullptr)
		{
		logger("cannot place new piece at a used location");
			return false;
		}
		board[location] = newPiece;
		return true;
	}

	bool moveStack(int startLocation, int destenyLocation,int stackSize, void* board[])  
	{
		int delta = abs(startLocation - destenyLocation);
		int isAcross = (startLocation + destenyLocation) % 5;

		if (stackSize > boardEdge) { logger("stack to high"); return false; }

		if((delta == 1 && isAcross==4)	||	(delta!=1)&&(delta!=5))
		{
			logger("action not allawed");
			return false;
		}

		
		
		
	}
}