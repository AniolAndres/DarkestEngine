#include "pch.h"
#include "ModuleWindow.h"

#include "Globals.h"
#include "SDL.h"
#include <assert.h>

ModuleWindow::ModuleWindow()
{
}


ModuleWindow::~ModuleWindow()
{
}

bool ModuleWindow::Init()
{
	bool result = true;

	if(SDL_Init(SDL_INIT_EVERYTHING )<0)
	{
		assert(0); //Failed SDL initialization
		result = false;
	}
	else
	{
		//Create and SDL window
		int width = SCREEN_WIDTH;
		int height = SCREEN_HEIGHT;

		Uint32 flags = SDL_WINDOW_SHOWN;	

		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if (window == nullptr)
		{
			assert(0); //Window could not be created
			result = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}

	}



	return result;
}

bool ModuleWindow::CleanUp()
{
	return false;
}
