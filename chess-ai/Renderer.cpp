#include "Renderer.h"
#include "Constants.h"
#include <iostream>

Renderer::Renderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::render(
	SDL_Window* window,
	Board* board,
	std::map<const int, SDL_Texture*> textureMap,
	int Perspective)
{
	Uint8 red = 44;
	Uint8 green = 47;
	Uint8 blue = 51;

	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
	SDL_RenderClear(renderer);

	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	int border;
	int xBorder, yBorder;
	if (w <= h) 
	{ 
		xBorder = (int)w * 0.3;
		yBorder = h - (w - (xBorder));
	}
	else 
	{ 
		yBorder = (int)h * 0.3;
		xBorder = w - (h - (yBorder));
	}

	int minimum = std::min({ w, h });
	int pieceSize = (minimum - std::min({ xBorder, yBorder })) / 8;

	int file = 0;
	int rank = 0;
	std::vector<int> boardVec = board->getBoard();

	SDL_Rect boardDestination;
	boardDestination.x = xBorder / 2;
	boardDestination.y = yBorder / 2;
	boardDestination.w = pieceSize * 8; boardDestination.h = boardDestination.w;
	SDL_RenderCopy(renderer, textureMap[1], NULL, &boardDestination);

	for (int i = 0; i < 64; i++)
	{
		int piece = boardVec[i];
		SDL_Rect destination;
		destination.x = (xBorder / 2)  + (file * pieceSize);
		destination.y = (yBorder / 2) + (8 * pieceSize) - ((rank + 1) * pieceSize);
		destination.w = pieceSize;
		destination.h = pieceSize;
		if (file == 7) { file = 0; rank += 1; }
		else { file++; }
		SDL_RenderCopy(renderer, textureMap[boardVec[i]], NULL, &destination);

	}
	SDL_RenderPresent(renderer);

	board->draw();
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}