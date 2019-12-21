#include "ModuleTime.h"

#include "SDL.h"

ModuleTime::ModuleTime()
{
}


ModuleTime::~ModuleTime()
{
}

bool ModuleTime::Init()
{
	lastTick = SDL_GetTicks();

	return true;
}

UpdateState ModuleTime::PreUpdate()
{
	int actualTicks = SDL_GetTicks();

	deltaTime = (actualTicks - lastTick) / 1000.0f;

	lastTick = actualTicks;

	return UpdateState::UpdateContinue;
}
