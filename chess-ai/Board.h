#pragma once
#include "SDL.h"
#include <vector>
#include <string>
#include <tuple>


static std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
static std::string testFEN = "1rk5/4n1R1/2p4p/1pP3pP/1N2b1P1/4Q3/PP6/1KR5 w - - 0 1";


class Board
{
public:
	Board() : board(64, 0) { Init(startFEN); }
	Board(std::string fen) : board(64, 0) { Init(fen); }
	~Board() {};
	std::vector<int> getBoard();

	void movePiece(int oldPos, int newPos);
	static std::pair<int, int> getRankAndFileFromBoardPos(int boardPos);

private:
	void Init(std::string fen);
	void loadBoardFromFen(std::string fen);
	std::vector<int> board;
	SDL_Texture* texture;
};

