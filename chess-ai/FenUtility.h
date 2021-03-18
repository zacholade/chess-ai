#pragma once
#include <string>
#include "Coord.h"
#include <vector>


class FenUtility
{
public:
	static bool checkFenFormat(std::string fen);
	static std::vector<int> getBoardLayout(std::string fenSegment);
	static bool getWhiteToMove(std::string fenSegment);
	static std::tuple<bool, bool, bool, bool> getCastlingRights(std::string fenSegment);
	static Coord* getEnPassant(std::string fenSegment);
	static int getHalfMoveClock(std::string fenSegment);
	static int getFullMoveNumber(std::string fenSegment);
};

