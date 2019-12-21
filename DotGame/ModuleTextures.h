#ifndef MODULETEXTURES_H
#define MODULETEXTURES_H

#include "Module.h"
#include <vector>

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init() override;

	SDL_Texture* Load(const char* path);
	void Unload(SDL_Texture* text);

	bool CleanUp() override;

private:
	std::vector<SDL_Texture*> textures;
};

#endif // MODULETEXTURES_H