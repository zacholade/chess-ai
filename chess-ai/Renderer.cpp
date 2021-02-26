#include "Renderer.h"


Renderer::Renderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}

void Renderer::render(Board* board, std::map<const char*, SDL_Texture*> textureMap)
{
	Uint8 red = 44;
	Uint8 green = 47;
	Uint8 blue = 51;

	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
	SDL_RenderClear(renderer);

	SDL_Rect srcrect;
	srcrect.x = 0;
    srcrect.y = 0;
	srcrect.w = 128;
	srcrect.h = 128;
	//dstrect.x = 640 / 2;
	//dstrect.y = 480 / 2;
	//dstrect.w = 32;
	//dstrect.h = 32;

	SDL_RenderCopy(renderer, textureMap["b_bishop"], NULL, &srcrect);
	SDL_RenderPresent(renderer);

	board->draw();
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}