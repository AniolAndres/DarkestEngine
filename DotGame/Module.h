#ifndef MODULE_H
#define MODULE_H

#include "Globals.h"

class Application;

class Module
{
public:
	Module() {};
	virtual ~Module() {};

	virtual bool Init() { return true; }

	virtual UpdateState PreUpdate() { return UpdateState::UpdateContinue; }
	virtual UpdateState Update() { return UpdateState::UpdateContinue; }
	virtual UpdateState PostUpdate() { return UpdateState::UpdateContinue; }

	virtual bool CleanUp() { return true; }

};

#endif // MODULE_H