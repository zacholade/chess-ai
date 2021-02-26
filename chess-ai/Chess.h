#pragma once
#include <SDL.h>
#include <map>
#include "Board.h"
#include "Renderer.h"


class Chess
{
public:
	Chess(SDL_Window* window, Renderer* renderer, std::map<const int, SDL_Texture*> textureMap);
	~Chess();
	void play();

private:
	SDL_Window* window;
	Renderer* renderer;
	std::map<const int, SDL_Texture*> textureMap;

	// Game loop logic.
	void gameLoop();
	void pollEvents();
	void render();

	// SDL event handlers.
	void handleMouseButtonDown();
	void handleMouseButtonUp();
	void handleMouseMovement();

	Board* board;
	bool shouldRun;
	int mouseX, mouseY;

	
};

