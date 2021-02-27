#pragma once
#include "SDL.h"
#include <map>
#include "Board.h"
#include "Window.h"

class Renderer
{
public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();
	void render(
	    Window* window, Board* board,
		std::map<const int,
		SDL_Texture*> textureMap,
		int perspective);
	SDL_Renderer* getRenderer();

private:
	SDL_Renderer* renderer;
	void renderBoard(Window* window, SDL_Texture* texture);
	void renderPieceAtMouse(Window* window, SDL_Texture* texture, int posX, int posY);
	void renderPiece(Window* window, SDL_Texture* texture, int rank, int file);
};