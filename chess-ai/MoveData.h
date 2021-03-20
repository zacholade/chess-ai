#pragma once
#include <list>
#include <map>


class MoveData
{
public:
	MoveData();
	~MoveData();

	const static int orthogonalOffsets[];
	const static int diagonalOffsets[];
	const static int tricardinalOffsets[];

	uint64_t getKnightAttackBitBoards();
	std::map<int, std::list<int>> getNumSquaresPerDirection();

private:
	void generateMoveData();

	uint64_t knightAttackBitBoards[64];
	std::map<int, std::list<int>> numSquaresPerDirection;
};

