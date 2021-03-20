#include "MoveData.h"
#include "BoardRepresentation.h"
#include <algorithm>
#include <map>
#include <list>

const int MoveData::orthogonalOffsets[] = { 1, -1, 8, -8 };  // Linear offsets
const int MoveData::diagonalOffsets[] = { 7, 9, -7, -9 };  // Diagonal offsets
const int MoveData::tricardinalOffsets[] = { 6, 10, 15, 17, -6, -10, -15, -17 };  // Knight offsets

MoveData::MoveData()
{
	generateMoveData();
}

MoveData::~MoveData()
{
}

uint64_t MoveData::getKnightAttackBitBoards()
{
	return uint64_t();
}

std::map<int, std::list<int>> MoveData::getNumSquaresPerDirection()
{
	return std::map<int, std::list<int>>();
}

// For each square (64) on the board, calculate the number of moves in each direction possible.
void MoveData::generateMoveData()
{
	// A map containing a list for each square on the chess board.
	// Each list contains 8 ints, denoting num squares to the edge of the board
	// excluding itself.
	static std::map<int, std::list<int>> numSquaresPerDirection;

	for (int squareIndex = 0; squareIndex < 64; squareIndex++)
	{
		int file = BoardRepresentation::fileIndex(squareIndex);
		int rank = BoardRepresentation::rankIndex(squareIndex);
		
		// Generate numSquaresPerDirection.
		int numN = 7 - rank;
		int numS = rank;
		int numW = file;
		int numE = 7 - file;
		numSquaresPerDirection[squareIndex] = {
			numN,
			numE,
			numS,
			numW,
			std::min(numN, numE),
			std::min(numS, numE),
			std::min(numS, numW),
			std::min(numN, numW),
		};

		// Generate knight attack bit boards.
		uint64_t knightBitBoard = 0;
		for (int knightOffset : tricardinalOffsets)
		{
			int knightAttackSquareIndex = squareIndex + knightOffset;

			if (knightAttackSquareIndex >= 0 && knightAttackSquareIndex < 64)
			{
				int knightAttackrank = BoardRepresentation::rankIndex(knightAttackSquareIndex);
				int knightAttackFile = BoardRepresentation::fileIndex(knightAttackSquareIndex);

				// This could wrap around side of board. Check file and rank have not changed more than 2.
				if (std::max(std::abs(file - knightAttackFile), std::abs(rank - knightAttackrank)) == 2)
				{
					knightBitBoard |= 1ULL << knightAttackSquareIndex;
				}
			}
		}
		knightAttackBitBoards[squareIndex] = knightBitBoard;
	}
}
