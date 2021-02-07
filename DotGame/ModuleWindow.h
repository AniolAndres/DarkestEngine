#ifndef MODULEWINDOW_H
#define MODULEWINDOW_H

#include "Module.h"

#include "SDL.h"

struct SDL_Window;
struct SDL_Surface;

class ModuleWindow :
	public Module
{
public:
	ModuleWindow();
	~ModuleWindow();

	bool Init() override;
	bool CleanUp() override;

	void Resize(int width, int height);

public:
	//The window we'll render
	SDL_Window* window = nullptr;

	//Window's surface
	SDL_Surface* screenSurface = nullptr;

	SDL_GLContext glContext;

private:
	int width = SCREEN_WIDTH;
	int height = SCREEN_HEIGHT;
};

#endif // MODULEWINDOW_H