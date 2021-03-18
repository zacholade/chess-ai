#include "FenUtility.h"
#include <map>
#include "Constants.h"
#include <stdexcept>
#include <iostream>
#include <tuple>
#include "BoardRepresentation.h"


bool FenUtility::checkFenFormat(std::string fen)
{
	// Returns true is FEN is properly formatted. False otherwise.
	int numSpaces = 0;
	int numRows = 1;
	for (const char& p : fen)
	{
		if (p == ' ') { ++numSpaces; }
		else if (p == '/') { ++numRows; }
	}

	if (numRows != 8 || numSpaces != 5) { return false; }
	return true;
}

std::vector<int> FenUtility::getBoardLayout(std::string fen)
{
	std::vector<int> board(64, 0);

	std::map<char, int> pieceFromChar = {
		{'k', Piece::King},
		{'p', Piece::Pawn},
		{'n', Piece::Knight},
		{'b', Piece::Bishop},
		{'r', Piece::Rook},
		{'q', Piece::Queen}
	};

	int rank = 7;
	int file = 0;
	int pieceColor;
	for (char& c : fen) {
		if (isdigit(c)) { file += (int)c - '0'; }
		else if (c == '/') { rank--; file = 0; }
		else {
			if (isupper(c)) { pieceColor = Piece::White; }
			else { pieceColor = Piece::Black; }
			int position = (rank * 8) + file;
			board[position] = pieceColor | pieceFromChar[tolower(c)];
			file++;
		}
	}
	return board;
}

bool FenUtility::getWhiteToMove(std::string fen)
{
	if (fen == "w") { return true; }
	// b otherwise.
	return false;
}

std::tuple<bool, bool, bool, bool> FenUtility::getCastlingRights(std::string fen)
{
	bool whiteKingSideCastleRights, whiteQueenSideCastleRights,
		 blackKingSideCastleRights, blackQueenSideCastleRights = false;

	if (fen != "-") {
		for (char& c : fen) {
			if (c == 'K') { whiteKingSideCastleRights = true; }
			else if (c == 'Q') { whiteQueenSideCastleRights = true; }
			else if (c == 'k') { blackKingSideCastleRights = true; }
			else if (c == 'q') { blackQueenSideCastleRights = true; }
		}
	}
	return std::make_tuple(whiteKingSideCastleRights,
						   whiteQueenSideCastleRights,
						   blackKingSideCastleRights,
						   blackQueenSideCastleRights);
}

Coord* FenUtility::getEnPassant(std::string fen)
{
	if (fen != "-") {
		int fileIndex = fen[1];
		int rankIndex = BoardRepresentation::fileIndexFromName(fen[0]);
		return new Coord(fileIndex, rankIndex);
	}
	return NULL;
}

int FenUtility::getHalfMoveClock(std::string fen)
{
	return std::stoi(fen);
}

int FenUtility::getFullMoveNumber(std::string fen)
{
	return std::stoi(fen);
}
