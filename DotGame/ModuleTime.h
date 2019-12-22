#ifndef MODULETIME_H
#define MODULETIME_H

#include "Module.h"

class ModuleTime : public Module
{
public:
	ModuleTime();
	~ModuleTime();

	bool Init() override;

	UpdateState PreUpdate() override;

public:

	float deltaTime = 0.0f;
	float acumulatedTime = 0.0f;

private:

	int lastTick = 0;


};

#endif // MODULETIME_H