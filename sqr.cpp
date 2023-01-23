
#include "sqr.h"
	
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

	bool basePtrStatus(){ return basePtr == nullptr ? false : true;}

	void addstack(int newStackSize, piece* nextPiece)
	{
		runnerPtr = basePtr;
		stackSize += newStackSize;

		if (basePtr == nullptr)
		{
			basePtr = nextPiece;
			runnerPtr = basePtr;
			return;
		}


		while (runnerPtr->getNext() != nullptr)
		{
			runnerPtr = runnerPtr->getNext();
		}
		runnerPtr->setNext(nextPiece);
		return ;
	}

	piece* cutStack(int stackToCut)
	{	
		piece* piecePtr = nullptr;
		int leftOver = stackSize - stackToCut;
		if (leftOver < 0) { return nullptr; }

		for (int i = 0; i < leftOver-1; i++) runnerPtr = runnerPtr->getNext();
		piecePtr = runnerPtr->getNext();
		runnerPtr->setNext(nullptr);
		return piecePtr;
	}

	void printSqr()
	{
		while (runnerPtr != nullptr)
		{
			runnerPtr->printPiece();
			runnerPtr = runnerPtr->getNext();
		}
	}
};




