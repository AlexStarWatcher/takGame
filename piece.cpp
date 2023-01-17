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
	
};