#include <iostream>
#include <map>

#include "Board.h"
#include "Constants.h"


void Board::Init(std::string fen)
{
	loadBoardFromFen(fen);
}

std::vector<int> Board::getBoard()
{
	return board;
}

void Board::movePiece(int oldPos, int newPos)
{
	// Picking up a piece and letting go shouldn't do anything.
	if (newPos != oldPos)
	{
		board[newPos] = board[oldPos];
		board[oldPos] = 0;
	}

}

void Board::loadBoardFromFen(std::string fen)
{
	std::map<char, int> pieceFromChar = {
		{'k', Piece::King},
		{'p', Piece::Pawn},
		{'n', Piece::Knight},
		{'b', Piece::Bishop},
		{'r', Piece::Rook},
		{'q', Piece::Queen}
	};

	printf("FEN: \"%s\"\n", fen.c_str());

	// Check fen is properly formatted.
	int numSpaces = 0;
	int numRows = 1;
	for (const char& p: fen)
	{
		if (p == ' ')
		{
			++numSpaces;
		}
		else if (p == '/')
		{
			++numRows;
		}
	}

	if (numRows != 8 || numSpaces != 5)
	{
		printf("Invalid FEN: \"%s\"\n", fen.c_str());
		throw new std::invalid_argument("Invalid FEN");
	}

	const char* p = fen.c_str();
	int rank = 7;
	int file = 0;
	int pieceColor;
	for (; *p != ' '; ++p)
	{
		const char c = *p;
		if (isdigit(c)) { file += (int)c - '0'; }
		else if (c == '/')
		{
			rank--;
			file = 0;
		}
		else
		{
			if (isupper(c)) { pieceColor = Piece::White; } else { pieceColor = Piece::Black; }
			int position = (rank * 8) + file;
			board[position] = pieceColor | pieceFromChar[tolower(c)];
			file++;
		}
	}

	int j = 1;
	for (int i : board)
	{
		std::cout << i << " ";
		if (i < 10) { std::cout << " "; }
		if (j % 8 == 0) { std::cout << "\n"; }
		j++;
	}
	std::cout << std::endl;
}
