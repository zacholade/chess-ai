#pragma once
class MoveData
{
public:
	const static int orthogonalOffsets[];
	const static int diagonalOffsets[];
	const static int tricardinalOffsets[];

	static void generateMoveData();

	const static uint64_t knightAttacks[64];
};

