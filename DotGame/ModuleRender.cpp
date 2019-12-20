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
	return true;
}
