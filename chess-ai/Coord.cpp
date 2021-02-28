#include "Coord.h"

Coord::Coord(int fileIndex, int rankIndex)
{
	this->fileIndex = fileIndex;
	this->rankIndex = rankIndex;
}

Coord::~Coord()
{
}

bool Coord::IsLightSquare()
{
	return (fileIndex + rankIndex) % 2 != 0;
}

