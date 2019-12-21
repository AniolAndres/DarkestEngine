#ifndef MODULERENDER_H
#define MODULERENDER_H

#include "Module.h"

struct SDL_Renderer;
struct SDL_Texture;

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
	bool Draw(SDL_Texture* texture, int x, int y,float size, SDL_Rect* section);

public:
	SDL_Renderer* renderer = nullptr;
};

#endif // MODULERENDER_H