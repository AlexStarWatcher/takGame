#pragma once

namespace utils
{
	enum stateEnum
	{
		whiteRoad = 0,
		blackRoad = 1,
		whiteWall = 2,
		blackWall = 3,
		whiteCap = 4,
		blackcap = 5,
		NA= 6
	};

	static int boardEdgeSize = 5;
	static bool boardInstenceCounter;
}