#pragma once
#include "SDL.h"
#include <vector>
#include <string>

static std::string startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


class Board
{
public:
	Board() : board(64, 0) { Init(startFEN); }
	Board(std::string fen) : board(64, 0) { Init(fen); }
	~Board() {};
	std::vector<int> getBoard();

private:
	void Init(std::string fen);
	void loadBoardFromFen(std::string fen);
	std::vector<int> board;
	SDL_Texture* texture;
};

