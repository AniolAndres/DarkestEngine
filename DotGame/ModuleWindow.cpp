#include "Application.h"

#include "ModuleWindow.h"
#include "ModuleRender.h"

#include "Globals.h"
#include "SDL.h"
#include <assert.h>
#include "GL/glew.h"

ModuleWindow::ModuleWindow()
{
}

ModuleWindow::~ModuleWindow()
{
}

bool ModuleWindow::Init()
{
	bool result = true;
	if(SDL_Init(SDL_INIT_VIDEO )<0)
	{
		assert(0); //Failed SDL initialization
		result = false;
	}
	else
	{
		//Create and SDL window
		int width = SCREEN_WIDTH * SCREEN_SIZE;
		int height = SCREEN_HEIGHT * SCREEN_SIZE;

		Uint32 flags = SDL_WINDOW_SHOWN;
		flags |= SDL_WINDOW_OPENGL;

		window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
		glContext = SDL_GL_CreateContext(window);

		if (window == nullptr)
		{
			assert(window != nullptr); //Window could not be created
			result = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
			SDL_SetWindowResizable(window, (SDL_bool)true);
			SDL_GetWindowSize(window, &width, &height);
		}

	}

	return result;
}

bool ModuleWindow::CleanUp()
{
	//Destroy SDL window
	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
		SDL_GL_DeleteContext(glContext);
	}

	SDL_Quit();
	return true;
}

void ModuleWindow::Resize(int width, int height)
{
	this->width = width;
	this->height = height;
}
