#pragma once
#include "SDL.h"
#include <map>
#include "Board.h"


class Renderer
{
public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();
	void render(Board* board, std::map<const char*, SDL_Texture*> textureMap);
	SDL_Renderer* getRenderer();

private:
	SDL_Renderer* renderer;
};