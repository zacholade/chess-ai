#pragma once
#include "Renderer.h"
#include <string>
#include <vector>
#include <map>


class Assets
{
public:
	static std::map<const int, SDL_Texture*> initAssets(Renderer* renderer);

private:
	static SDL_Texture* loadTexture(std::string, Renderer*);
};

