#ifndef _MODULEGRAPHICS_H_
#define _MODULEGRAPHICS_H_

#include "Module.h"

class ModuleGraphics :
    public Module
{
public:
	ModuleGraphics();
	~ModuleGraphics();

	bool Init() override;
	UpdateState PreUpdate() override;
	UpdateState PostUpdate() override;
	bool CleanUp() override;

};

#endif