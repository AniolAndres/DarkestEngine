#ifndef MODULEWINDOW_H
#define MODULEWINDOW_H

#include "Module.h"

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

private:
	//The window we'll render
	SDL_Window* window = nullptr;

	//Window's surface
	SDL_Surface* screenSurface = nullptr;
};

#endif // MODULEWINDOW_H