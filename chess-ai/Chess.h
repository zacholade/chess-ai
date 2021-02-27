#pragma once
#include <SDL.h>
#include <map>
#include "Board.h"
#include "Renderer.h"
#include "Window.h"


class Chess
{
public:
	Chess(Window* window, Renderer* renderer, std::map<const int, SDL_Texture*> textureMap);
	~Chess();
	void play();

private:
	Window* window;
	Renderer* renderer;
	std::map<const int, SDL_Texture*> textureMap;

	// Game loop logic.
	void gameLoop();
	void pollEvents();
	void render();

	Board* board;
	bool shouldRun;
	bool whiteToMove;
};

