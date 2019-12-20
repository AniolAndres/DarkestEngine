#ifndef MODULERENDER_H
#define MODULERENDER_H

#include "Module.h"
class ModuleRender :
	public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init() override;
	bool CleanUp() override;
};

#endif // MODULERENDER_H