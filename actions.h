#pragma once


namespace actions {

	static int boardEdge;
	static bool boardInstenceCounter;
	static void* board;

	void setSize();

	void cleanSlate();

	bool boardbilder();

	bool placePiece(piece* newPiece, int location, void* board[]);

	bool moveStack(int startLocation, int destenyLocation, int stackSize, void* board[]);
}