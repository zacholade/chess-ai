#pragma once
#include "SDL.h"

static char startFEN[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


class Board
{
public:
	Board();
	Board(char fen[]);
	~Board();
	void draw();

private:
	void Init(char fen[]);
	void loadBoardFromFen(char fen[]);
	int board[64] = { 0 };
	SDL_Texture* texture;
};

