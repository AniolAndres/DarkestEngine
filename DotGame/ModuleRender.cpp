#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"

#include "SDL.h"
#include <assert.h>

ModuleRender::ModuleRender()
{
}


ModuleRender::~ModuleRender()
{
}

bool ModuleRender::Init()
{
	bool result = true;
	

	Uint32 flags = 0;

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == nullptr)
	{
		assert(0); //Renderer could not be created
		result = false;
	}

	return result;
}

UpdateState ModuleRender::PreUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	return UpdateState::UpdateContinue;
}

UpdateState ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return UpdateState::UpdateContinue;
}

bool ModuleRender::CleanUp()
{
	//Destroy window
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}
	return true;
}

bool ModuleRender::Draw(SDL_Texture* texture, int x, int y,float size, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x * SCREEN_SIZE;
	rect.y = y * SCREEN_SIZE;

	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE / size;
	rect.h *= SCREEN_SIZE / size;

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		assert(0); //Could not blit to screen
		ret = false;
	}

	return ret;
}
