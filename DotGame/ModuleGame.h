#ifndef MODULEGAME_H
#define MODULEGAME_H

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Rect;

class ModuleGame : public Module
{
public:
	ModuleGame();
	~ModuleGame();

	bool Init();

	UpdateState Update() override;

private:

	SDL_Texture* greenCircle = nullptr;
	SDL_Rect greenCircleRectangle;

};

#endif // MODULEEGAME_H