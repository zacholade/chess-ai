#pragma once
#include "SDL.h"
#include <map>
#include <algorithm>
#include "Board.h"

class Renderer
{
public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();
	void render(
		SDL_Window* window, Board* board,
		std::map<const int,
		SDL_Texture*> textureMap,
		int perspective);
	SDL_Renderer* getRenderer();

private:
	SDL_Renderer* renderer;
};