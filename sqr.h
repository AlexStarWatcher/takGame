#pragma once

#include "logger.h"
#include "piece.h"
#include "actions.h"
#include "utils.h"


struct sqr
{
	sqr();
	bool addstack(int stack, piece* nextPiece);
	piece* cutStack(int stack);	
};