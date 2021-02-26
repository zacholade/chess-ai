#pragma once
#include "SDL.h"
#include <vector>

static char startFEN[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


class Board
{
public:
	Board() : board(64, 0) { Init(startFEN); }
	Board(char fen[]) : board(64, 0) { Init(fen); }
	~Board();
	void draw();
	std::vector<int> getBoard();

private:
	void Init(char fen[]);
	void loadBoardFromFen(char fen[]);
	std::vector<int> board;
	SDL_Texture* texture;
};

