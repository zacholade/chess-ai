#include <iostream>
#include <map>

#include "Board.h"
#include "Piece.h"


Board::Board()
{
	Init(startFEN);
}

Board::Board(char fen[])
{
	Init(fen);
}

Board::~Board()
{

}

void Board::Init(char fen[])
{
	loadBoardFromFen(fen);
}

void Board::draw()
{

}

void Board::loadBoardFromFen(char fen[])
{
	std::map<char, int> pieceFromChar = {
		{'k', Piece::King},
		{'p', Piece::Pawn},
		{'n', Piece::Knight},
		{'b', Piece::Bishop},
		{'r', Piece::Rook},
		{'q', Piece::Queen}
	};

	printf("FEN: \"%s\"\n", fen);

	// Check fen is properly formatted.
	int numSpaces = 0;
	int numRows = 1;
	for (const char* p = fen; *p != 0; ++p)
	{
		if (*p == ' ')
		{
			++numSpaces;
		}
		else if (*p == '/')
		{
			++numRows;
		}
	}

	if (numRows != 8 || numSpaces != 5)
	{
		printf("Invalid FEN: \"%s\"\n", fen);
		throw new std::invalid_argument("Invalid FEN");
	}

	const char* p = fen;
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
			board[(rank * 8) + file] = pieceColor | pieceFromChar[tolower(c)];
			file++;
		}
	}
}
