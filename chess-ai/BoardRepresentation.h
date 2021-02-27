#pragma once
#include <string>
#include "Coord.h"


static class BoardRepresentation
{
public:
	static const std::string fileNames;
	static const std::string rankNames;

	static int fileIndex(int squareIndex);
	static int rankIndex(int squareIndex);

	static int indexFromCoord(int fileIndex, int rankIndex);
	static Coord coordFromIndex(int squareIndex);

	static std::string squareNameFromCoord(int fileIndex, int rankIndex);
	static std::string squareNameFromCoord(int squareIndex);
	static std::string squareNameFromCoord(Coord coord);

	static bool lightSquare(int fileIndex, int rankIndex);

};

