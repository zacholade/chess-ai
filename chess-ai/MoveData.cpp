#include "MoveData.h"
#include "BoardRepresentation.h"
#include <algorithm>
#include <map>
#include <list>

const int MoveData::orthogonalOffsets[] = { 1, -1, 8, -8 };  // Linear offsets
const int MoveData::diagonalOffsets[] = { 7, 9, -7, -9 };  // Diagonal offsets
const int MoveData::tricardinalOffsets[] = { 6, 10, 15, 17, -6, -10, -15, -17 };  // Knight offsets


// For each square (64) on the board, calculate the number of moves in each direction possible.
void MoveData::generateMoveData()
{
	// A map containing a list for each square on the chess board.
	// Each list contains 8 ints, denoting num squares to the edge of the board
	// excluding itself.
	std::map<int, std::list<int>> numSquaresPerDirection;

	for (int file = 0; file < 8; file++)
	{
		for (int rank = 0; rank < 8; rank++)
		{
			int squareIndex = BoardRepresentation::indexFromCoord(file, rank);
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
		}
	}


}
