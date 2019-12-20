#ifndef MODULERENDER_H
#define MODULERENDER_H

#include "Module.h"

struct SDL_Renderer;

class ModuleRender :
	public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init() override;

	UpdateState PreUpdate() override;
	UpdateState PostUpdate() override;

	bool CleanUp() override;

public:
	SDL_Renderer* renderer = nullptr;

};

#endif // MODULERENDER_H