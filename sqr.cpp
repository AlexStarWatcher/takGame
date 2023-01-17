#include "board.h"
	
struct sqr
{	
private:
	int stackSize;
	piece* basePtr;
	piece* runnerPtr;


public:

	sqr()
	{
		basePtr = nullptr;
		runnerPtr = nullptr;
		stackSize = 0;
	}

	bool addstack(int stack, piece* nextPiece)
	{
		runnerPtr = basePtr;
		stackSize += stack;

		if (basePtr == nullptr)
		{
			basePtr = nextPiece;
			runnerPtr = basePtr;
			return true;
		}


		while (runnerPtr->getNext() != nullptr)
		{
			runnerPtr = runnerPtr->getNext();
		}
		runnerPtr->setNext(nextPiece);
		return true;
	}

	piece* cutStack(int stack)
	{	
		piece* piecePtr = nullptr;
		int leftOver = stackSize - stack;
		if (leftOver < 0) { return nullptr; }

		for (int i = 0; i < leftOver-1; i++) runnerPtr = runnerPtr->getNext();
		piecePtr = runnerPtr->getNext();
		runnerPtr->setNext(nullptr);
		return piecePtr;
	}
};




