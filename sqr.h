#pragma once

#include "logger.h"
#include "piece.h"
#include "actions.h"
#include "utils.h"


struct sqr
{
	sqr();
	bool basePtrStatus();
	void addstack(int newStackSize, piece* nextPiece);
	piece* cutStack(int stackToCut);
	void printSqr();
};