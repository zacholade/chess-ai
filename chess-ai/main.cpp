#include <iostream>
#include <SDL.h>
#include "Assets.h"
#include "Chess.h"

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow(
		"Chess AI",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		400,
		SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		printf("Could not create the window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Renderer* sdl_renderer = SDL_CreateRenderer(
		window,
		-1,
		0
	);

	Renderer* renderer = new Renderer(sdl_renderer);
	std::map<const char*, SDL_Texture*> textureMap = Assets::initAssets(renderer);

	Chess* chess = new Chess(window, renderer, textureMap);
	chess->play();

	
	// Tidy up now we have left the game loop.
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
