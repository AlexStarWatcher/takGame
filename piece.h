#pragma once
#include "logger.h"
#include "utils.h"
#include <string>



class piece {
public:

	piece() = delete;
	piece(utils::stateEnum stateColor);

	piece* getNext();
	void setNext(piece* next);
	utils::stateEnum getState();
	void toppel();
	std::string getStringedState();
	void printPiece()
};