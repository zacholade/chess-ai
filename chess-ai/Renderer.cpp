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

	renderBoard(window, textureMap[1]);

	// Loop over all the pieces on the board and draw them in
	// their corresponding position. Accounting for window size & borders.
	int file = 0;
	int rank = 0;
	int heldPiecePos = board->getHeldBoardPosition();
	std::vector<int> boardVec = board->getBoard();
	for (int i = 0; i < 64; i++)
	{
		// We want the piece held by the mouse to render on top.
		if (i != heldPiecePos) { renderPiece(window, textureMap[boardVec[i]], rank, file); }
		if (file == 7) { file = 0; rank += 1; }
		else { file++; }
	}

	if (heldPiecePos != -1)
	{
		renderPieceAtScreenPos(window, textureMap[boardVec[heldPiecePos]], window->getMouseX(), window->getMouseY());
	}
	// We are done drawing to this buffer. Present it.
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}

void Renderer::renderBoard(Window* window, SDL_Texture* texture)
{
	int borderWidth = window->getBorderWidth();
	int borderHeight = window->getBorderHeight();
	int pieceSize = window->getPieceSize();

	// Draw the 8x8 grid board background.
	SDL_Rect dest;
	dest.x = borderWidth / 2;
	dest.y = borderHeight / 2;
	dest.w = pieceSize * 8; dest.h = dest.w;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}
void Renderer::renderPieceAtScreenPos(Window* window, SDL_Texture* texture, int posX, int posY)
{
	int pieceSize = window->getPieceSize();

	SDL_Rect dest;
	dest.x = posX - (pieceSize / 2);
	dest.y = posY - (pieceSize / 2);
	dest.w = pieceSize;
	dest.h = pieceSize;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Renderer::renderPiece(Window* window, SDL_Texture* texture, int rank, int file)
{
	int borderWidth = window->getBorderWidth();
	int borderHeight = window->getBorderHeight();
	int pieceSize = window->getPieceSize();

	SDL_Rect dest;
	dest.x = (borderWidth / 2) + (file * pieceSize);
	dest.y = (borderHeight / 2) + (8 * pieceSize) - ((rank + 1) * pieceSize);
	dest.w = pieceSize;
	dest.h = pieceSize;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}
