#include "Assets.h"
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"


std::map<const int, SDL_Texture*> Assets::initAssets(Renderer* renderer)
{
	static std::map<const int, SDL_Texture*> textureMap;
	std::string root = "assets/";

	std::vector<std::pair<const int, const char*>> imgPathsToLoad;
	imgPathsToLoad.push_back(std::make_pair(18, "black_pawn.png"));
	imgPathsToLoad.push_back(std::make_pair(10, "white_pawn.png"));
	imgPathsToLoad.push_back(std::make_pair(21, "black_rook.png"));
	imgPathsToLoad.push_back(std::make_pair(13, "white_rook.png"));
	imgPathsToLoad.push_back(std::make_pair(19, "black_knight.png"));
	imgPathsToLoad.push_back(std::make_pair(11, "white_knight.png"));
	imgPathsToLoad.push_back(std::make_pair(20, "black_bishop.png"));
	imgPathsToLoad.push_back(std::make_pair(12, "white_bishop.png"));
	imgPathsToLoad.push_back(std::make_pair(17, "black_king.png"));
	imgPathsToLoad.push_back(std::make_pair(9, "white_king.png"));
	imgPathsToLoad.push_back(std::make_pair(22, "black_queen.png"));
	imgPathsToLoad.push_back(std::make_pair(14, "white_queen.png"));

	for (std::pair<const int, const char*> pair : imgPathsToLoad)
	{

		std::string completePath = root;
		completePath += pair.second;
		SDL_Texture* texture = loadTexture(completePath, renderer);
		textureMap.insert({ pair.first, texture });
	}

	std::string boardPath = root;
	boardPath += "chess_board.png";
	SDL_Texture* boardTexture = loadTexture(boardPath, renderer);
	textureMap.insert({ 1, boardTexture });

	return textureMap;
}

SDL_Texture* Assets::loadTexture(std::string path, Renderer* renderer)
{
	SDL_Texture* texture;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
	{
		printf("Unable to load chess background image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(renderer->getRenderer(), surface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			SDL_FreeSurface(surface);
		}
		//Get rid of old loaded surface
		else
		{
			SDL_FreeSurface(surface);
			return texture;
		}
	}
	return NULL;
}
