#ifndef MODULEINPUT_H
#define MODULEINPUT_H

#include "Module.h"


class ModuleInput :
	public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool Init() override;
	bool CleanUp() override;
};

#endif // MODULEINPUT_H