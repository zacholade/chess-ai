#include <iostream>
#include "Chess.h"
#include "SDL_image.h"
#include "Constants.h"


Chess::Chess(Window* window, Renderer* renderer, std::map<const int, SDL_Texture*> textureMap)
{
	this->window = window;
    this->renderer = renderer;
	this->textureMap = textureMap;
	board = new Board(testFEN);

	shouldRun = true;
}

Chess::~Chess()
{

}

void Chess::play()
{
	gameLoop();
}

void Chess::gameLoop()
{
	while (shouldRun)
	{
		pollEvents();
		render();
	}
}

void Chess::pollEvents()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_WINDOWEVENT:
			if (e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				printf("window_r");
				window->handleWindowResized(e.window.data1, e.window.data2);
			}

			break;

		case SDL_QUIT:
			printf("Quit Event Polled. Closing..\n");
			shouldRun = false;

		case SDL_MOUSEBUTTONDOWN:
			printf("MBD\n");
			window->handleMouseButtonDown(board);
			break;

		case SDL_MOUSEBUTTONUP:
			printf("MBU\n");
			window->handleMouseButtonUp();
			break;
		
		case SDL_MOUSEMOTION:
			window->handleMouseMovement();
			break;
		
		}
	}

}

void Chess::render()
{
	renderer->render(window, board, textureMap, Perspective::White);
}

