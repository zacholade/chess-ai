#include <iostream>
#include <map>

#include "Board.h"
#include "Constants.h"
#include "FenUtility.h"


void Board::Init(std::string fen)
{
	loadBoardFromFen(fen);
}

std::vector<int> Board::getBoard()
{
	return board;
}

int Board::getHeldBoardPosition()
{
	return heldBoardPosition;
}

void Board::setHeldBoardPosition(int pos)
{
	heldBoardPosition = pos;
}

void Board::movePiece(int oldPos, int newPos)
{
	// Picking up a piece and letting go shouldn't do anything.
	if (newPos != oldPos)
	{
		board[newPos] = board[oldPos];
		board[oldPos] = Piece::None;
	}
}

std::pair<int, int> Board::getRankAndFileFromBoardPos(int boardPos)
{
	int rank, file;
	rank = (double)boardPos / (double)8;
	file = boardPos % 8;
	return std::pair<int, int>(rank, file);
}

void Board::loadBoardFromFen(std::string fen)
{
	printf("FEN: \"%s\"\n", fen.c_str());

	if (!FenUtility::checkFenFormat(fen))
	{
		printf("Invalid FEN: \"%s\"\n", fen.c_str());
		throw new std::invalid_argument("Invalid FEN");
	}

	std::string delimiter = " ";
	std::string token;
	int i = 0;
	size_t position = 0;
	size_t last = 0;
	size_t next = 0;
	std::vector<std::string> fenList;
	while ((next = fen.find(delimiter, last)) != std::string::npos) {
		token = fen.substr(last, next - last);
		last = next + 1;
		fenList.push_back(token);
		//fen.erase(0, position + delimiter.length());
	}
	fenList.push_back(fen.substr(last));

	board = FenUtility::getBoardLayout(fenList[0]);
	whiteToMove = FenUtility::getWhiteToMove(fenList[1]);

	std::tuple<bool, bool, bool, bool> castlingRights = FenUtility::getCastlingRights(fenList[2]);
	whiteKingSideCastleRights = std::get<0>(castlingRights);
	whiteQueenSideCastleRights = std::get<1>(castlingRights);
	blackKingSideCastleRights = std::get<2>(castlingRights);
	blackQueenSideCastleRights = std::get<3>(castlingRights);

	enPassantPosition = FenUtility::getEnPassant(fenList[3]);

	halfMoveClock = FenUtility::getHalfMoveClock(fenList[4]);
	fullMoveNumber =  FenUtility::getFullMoveNumber(fenList[5]);
}
