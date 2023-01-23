#include "piece.h"

class piece
{

	utils::stateEnum pieceStateColor;
	piece* nextPiecePtr ;

public:

	piece() = delete;

	piece(utils::stateEnum stateColor) :pieceStateColor(stateColor)
	{nextPiecePtr = nullptr;}

	piece* getNext() { return nextPiecePtr; }

	void setNext(piece* next) { this->nextPiecePtr = next; }

	utils::stateEnum getState() { return pieceStateColor; };

	void toppel()
	{
		if (pieceStateColor == utils::whiteWall)
			pieceStateColor = utils::whiteRoad;

		if(pieceStateColor == utils::blackWall) 
			pieceStateColor = utils::blackRoad;
	}

	std::string getStringedState()
	{
		switch (pieceStateColor) 
		{
		case 0:
			return "white Road";
			break;
		case 1:
			return"black Road";
			break;
		case 2:
			return "white Wall";
			break;
		case 3:
			return "black Wall";
			break;
		case 4:
			return "white Cap";
			break;
		case 5:
			return "black Cap";
			break;
		default:
			return "n/a";
			break;
		}
	}
	void printPiece()
	{
		logger(this->getStringedState()+"|");
	}
};



 = 4,

blackcap = 5,
NA = 6