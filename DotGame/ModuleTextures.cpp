#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

#include "SDL.h"
#include "SDL_image.h"

#include <assert.h>
#include <iostream>

ModuleTextures::ModuleTextures()
{
}


ModuleTextures::~ModuleTextures()
{
}

bool ModuleTextures::Init()
{
	bool result = true;

	int flags = IMG_INIT_PNG;
	int init = IMG_Init(flags);

	if (init == 0)
	{
		std::cout << "Could not initialize texture module with: " << IMG_GetError() << std::endl;
		assert(init); // Could not initialize texture module correctly
		result = false;
	}

	return result;
}

SDL_Texture * ModuleTextures::Load(const char * path)
{
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = IMG_Load(path);

	if (surface == nullptr)
	{
		std::cout << "Could not create surface because: " << SDL_GetError() << std::endl;
		assert(0); //Surface could not be created!
		
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(App->render->renderer, surface);

		if (texture == nullptr)
		{
			assert(0); //Texture could not be created!
		}
		else
		{
			textures.push_back(texture);
		}

		SDL_FreeSurface(surface);
	}

	return texture;
}

void ModuleTextures::Unload(SDL_Texture* text)
{
	std::vector<SDL_Texture*>::iterator eraseIt;
	bool found = false;

	for (std::vector<SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		if (*it == text)
		{
			eraseIt = it;
			found = true;
		}
	}

	if (found)
	{
		SDL_DestroyTexture(*eraseIt);
		textures.erase(eraseIt);
	}	
}

bool ModuleTextures::CleanUp()
{
	bool result = true;

	for (std::vector<SDL_Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		SDL_DestroyTexture(*it);
	}

	textures.clear();

	return result;
}
