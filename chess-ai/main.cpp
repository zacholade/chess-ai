#include <iostream>
#include <SDL.h>
#include "Assets.h"
#include "Chess.h"
#include "Window.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* sdl_window = SDL_CreateWindow(
		"Chess AI",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1000,
		720,
		SDL_WINDOW_SHOWN
	);

	if (sdl_window == nullptr) {
		printf("Could not create the window: %s\n", SDL_GetError());
		return 1;
	}

	Window* window = new Window(sdl_window);

	SDL_SetWindowResizable(sdl_window, SDL_TRUE);


	SDL_Renderer* sdl_renderer = SDL_CreateRenderer(
		sdl_window,
		-1,
		0
	);

	Renderer* renderer = new Renderer(sdl_renderer);
	std::map<const int, SDL_Texture*> textureMap = Assets::initAssets(renderer);

	Chess* chess = new Chess(window, renderer, textureMap);
	chess->play();

	
	// Tidy up now we have left the game loop.
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
	return 0;
}
