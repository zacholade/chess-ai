#pragma once
#include "SDL.h"
#include <vector>
#include <string>
#include <tuple>
#include "Coord.h"


const static std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
const static std::string testFEN = "1rk5/4n1R1/2p4p/1pP3pP/1N2b1P1/4Q3/PP6/1KR5 w - - 0 1";


class Board
{
public:
	Board() { heldBoardPosition = -1; Init(startFEN); }
	Board(std::string fen) { heldBoardPosition = -1; Init(fen); }
	~Board() {};
	std::vector<int> getBoard();

	int getHeldBoardPosition();
	void setHeldBoardPosition(int pos);

	void movePiece(int oldPos, int newPos);
	static std::pair<int, int> getRankAndFileFromBoardPos(int boardPos);


private:
	void Init(std::string fen);
	void loadBoardFromFen(std::string fen);
	std::vector<int> board;
	bool whiteToMove;

	// Denotes castle rights. Only changes to false if king/rook move.
	// Doesn't account for if king will move over square being attacked.
	bool whiteKingSideCastleRights;
	bool whiteQueenSideCastleRights;
	bool blackKingSideCastleRights;
	bool blackQueenSideCastleRights;
	Coord* enPassantPosition;

	int halfMoveClock;
	int fullMoveNumber;


	SDL_Texture* texture;
	// Denotes the board position relating to the piece which is currently
	// being held by the mouse (holding left click + dragging around)
	// -1 means no piece
	int heldBoardPosition;
};

