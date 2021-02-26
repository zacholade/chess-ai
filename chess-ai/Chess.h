#pragma once
#include <SDL.h>
#include <map>
#include "Board.h"
#include "Renderer.h"


class Chess
{
public:
	Chess(SDL_Window* window, Renderer* renderer, std::map<const char*, SDL_Texture*> textureMap);
	~Chess();
	void play();

private:
	SDL_Window* window;
	Renderer* renderer;
	std::map<const char*, SDL_Texture*> textureMap;

	void gameLoop();
	void pollEvents();
	void render();

	Board* board;
	bool shouldRun;

	
};

