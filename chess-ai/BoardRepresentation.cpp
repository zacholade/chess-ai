#include "BoardRepresentation.h"
#include <iostream>
const std::string BoardRepresentation::fileNames = "abcdefgh";
const std::string BoardRepresentation::rankNames = "12345678";

int BoardRepresentation::fileIndex(int squareIndex)
{
	// Bit wise And on the 
	return squareIndex & 0b000111;
}

int BoardRepresentation::rankIndex(int squareIndex)
{
	return squareIndex >> 3;
}

int BoardRepresentation::indexFromCoord(int fileIndex, int rankIndex)
{
	return rankIndex * 8 + fileIndex;
}

Coord BoardRepresentation::coordFromIndex(int squareIndex)
{
	return Coord(fileIndex(squareIndex), rankIndex(squareIndex));
}

std::string BoardRepresentation::squareNameFromCoord(int fileIndex, int rankIndex)
{ 
	return std::string(1, fileNames[fileIndex]) + rankNames[rankIndex];
}

std::string BoardRepresentation::squareNameFromCoord(int squareIndex)
{
	return squareNameFromCoord(rankIndex(squareIndex), fileIndex(squareIndex));
}

std::string BoardRepresentation::squareNameFromCoord(Coord coord)
{
	return squareNameFromCoord(coord.fileIndex, coord.rankIndex);
}

bool BoardRepresentation::lightSquare(int fileIndex, int rankIndex)
{
	return (fileIndex + rankIndex) % 2 != 0;
}
