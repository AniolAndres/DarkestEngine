#ifndef MODULEGAME_H
#define MODULEGAME_H

#include "Module.h"
class ModuleGame : public Module
{
public:
	ModuleGame();
	~ModuleGame();

	bool Init();

	UpdateState Update() override; //
};

#endif // MODULEEGAME_H