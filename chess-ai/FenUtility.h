#pragma once
#include <string>
#include "Coord.h"
#include <vector>


class FenUtility
{
public:
	static bool checkFenFormat(std::string fen);
	static std::vector<int> getBoardLayout(std::string fen);
	static bool getWhiteToMove(std::string fen);
	static std::tuple<bool, bool, bool, bool> getCastlingRights(std::string fen);
	static Coord* getEnPassant(std::string fen);
	static int getHalfMoveClock(std::string fen);
	static int getFullMoveNumber(std::string fen);
};

