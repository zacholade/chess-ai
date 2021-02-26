#include <iostream>
#include "Chess.h"
#include "SDL_image.h"



Chess::Chess(SDL_Window* window, Renderer* renderer, std::map<const char*, SDL_Texture*> textureMap)
{
	this->window = window;
    this->renderer = renderer;
	this->textureMap = textureMap;
	shouldRun = true;

	board = new Board();
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
		if (e.type == SDL_QUIT)
		{
			printf("Quit Event Polled. Closing..\n");
			shouldRun = false;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			printf("MBD\n");
		}
	}
}

void Chess::render()
{
	renderer->render(board, textureMap);
}