#pragma once
#include <SDL.h>
#include <tuple>
#include "Board.h"
#include <algorithm>

class Window
{
public:
	Window(SDL_Window* window);
	~Window();

	SDL_Window* getWindow();
	int getBoardPosition(Board* board, int mouseX, int mouseY);

	std::pair<int, int> getMousePos();
	int getMouseX();
	int getMouseY();

	int getWidth();
	int getHeight();

	int getBorderWidth();
	int getBorderHeight();
	const float getBorderScale();

	int getPieceSize();

	// SDL event handlers.
	void handleMouseButtonDown(Board* board);
	void handleMouseButtonUp(Board* board);
	void handleMouseMovement();
	void handleWindowResized(int width, int height);

private:
	SDL_Window* window;
	float borderScale;
	int width, height;
	int mouseX, mouseY;

	int borderWidth, borderHeight;
	int pieceSize;
};