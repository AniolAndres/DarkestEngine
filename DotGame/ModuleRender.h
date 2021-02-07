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
	void CreateTriangle();

public:
	SDL_Renderer* renderer = nullptr;
	float vertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
};

#endif // MODULERENDER_H