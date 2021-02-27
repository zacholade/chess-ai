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
	int getWidth();
	int getHeight();
	float getBorderScale();
	std::pair<int, int> getMousePos();

	// SDL event handlers.
	void handleMouseButtonDown(Board* board);
	void handleMouseButtonUp();
	void handleMouseMovement();
	void handleWindowResized(SDL_Event event);

private:
	SDL_Window* window;
	float borderScale;
	int width, height;
	int mouseX, mouseY;
};

