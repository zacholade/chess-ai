#pragma once
class MoveData
{
	const static int orthogonalOffsets[];
	const static int diagonalOffsets[];
	const static int tricardinalOffsets[];

	static void generateMoveData();
};

