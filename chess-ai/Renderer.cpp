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
	Window* window,
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
	int w = window->getWidth();
	int h = window->getHeight();
	SDL_GetWindowSize(window->getWindow(), &w, &h);

	int borderWidth = window->getBorderWidth();
	int borderHeight = window->getBorderHeight();
	int pieceSize = window->getPieceSize();

	// Draw the 8x8 grid board background.
	SDL_Rect boardDestination;
	boardDestination.x = borderWidth / 2;
	boardDestination.y = borderHeight / 2;
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
		if (i == window->getHeldBoardPosition())
		{
			destination.x = window->getMouseX() - (pieceSize / 2);
			destination.y = window->getMouseY() - (pieceSize / 2);
		}
		else
		{
			destination.x = (borderWidth / 2) + (file * pieceSize);
			destination.y = (borderHeight / 2) + (8 * pieceSize) - ((rank + 1) * pieceSize);
		}
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