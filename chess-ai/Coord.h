#pragma once
class Coord
{
public:
	Coord(int fileIndex, int rankIndex);
	~Coord();

	int fileIndex;
	int rankIndex;

	bool IsLightSquare();
};

