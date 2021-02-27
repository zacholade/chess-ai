#pragma once
#include <SDL.h>
#include <tuple>
#include "Board.h"

class Window
{
public:
	Window(SDL_Window* window);
	~Window();

	SDL_Window* getWindow();
	int getBoardPosition(Board* board, int mouseX, int mouseY);
	float getBorderWidth();
	int getMouseX();
	int getMouseY();
	std::pair<int, int> getMousePos();

	// SDL event handlers.
	void handleMouseButtonDown();
	void handleMouseButtonUp();
	void handleMouseMovement();

private:
	SDL_Window* window;
	float borderWidth;
	int mouseX, mouseY;
};

