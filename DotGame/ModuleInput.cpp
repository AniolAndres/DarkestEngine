
#include "Globals.h"
#include "ModuleInput.h"

#include "SDL.h"

ModuleInput::ModuleInput()
{
}

ModuleInput::~ModuleInput()
{
}

bool ModuleInput::Init()
{
	bool result = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		result = false;
	}

	return result;
}

UpdateState ModuleInput::PreUpdate()
{
	static SDL_Event event;

	for (int i = 0; i < NUM_MOUSE_BUTTONS; ++i)
	{
		if (mouseButtons[i] == KeyState::KeyDown)
			mouseButtons[i] = KeyState::KeyRepeat;

		if (mouseButtons[i] == KeyState::KeyUp)
			mouseButtons[i] = KeyState::KeyIdle;
	}

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		}
	}

	if (GetWindowEvent(EventWindow::EventQuit) == true)
		return UpdateState::UpdateStop;

	return UpdateState::UpdateContinue;
}

bool ModuleInput::CleanUp()
{
	return true;
}

bool ModuleInput::GetWindowEvent(EventWindow event) const
{
	return true;
	/*return windowEvents[event];*/
}
