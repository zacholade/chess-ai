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

	// Set the background colour to off black for the window.
	Uint8 red = 44;
	Uint8 green = 47;
	Uint8 blue = 51;
	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

	// Clears the window and sets the background colour to the one specified above.
	SDL_RenderClear(renderer);

	// Retrieve the size of the window.
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	int xBorder, yBorder;
	float boarderScale = 0.15;

	// We need to work out whether width or height is shorter.
	// We scale the board based off the shortest axis.
	if (w <= h) { xBorder = (int)w * boarderScale; yBorder = h - (w - (xBorder)); }
	else { yBorder = (int)h * boarderScale; xBorder = w - (h - (yBorder)); }
	int minimum = std::min({ w, h });
	int pieceSize = (minimum - std::min({ xBorder, yBorder })) / 8;

	// Draw the 8x8 grid board background.
	SDL_Rect boardDestination;
	boardDestination.x = xBorder / 2;
	boardDestination.y = yBorder / 2;
	boardDestination.w = pieceSize * 8; boardDestination.h = boardDestination.w;
	SDL_RenderCopy(renderer, textureMap[1], NULL, &boardDestination);

	// Loop over all the pieces on the board and draw them in
	// their corresponding position. Accounting for window size & borders.
	int file = 0;
	int rank = 0;
	std::vector<int> boardVec = board->getBoard();
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

	// We are done drawing to this buffer. Present it.
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}