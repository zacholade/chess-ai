#pragma once
class MoveData
{
public:
	const static int orthogonalOffsets[];
	const static int diagonalOffsets[];
	const static int tricardinalOffsets[];

	static void generateMoveData();

	const static unsigned long long knightAttacks[64];
};

