
#include "Globals.h"
#include "ModuleInput.h"
#include "ModuleWindow.h"
#include "Application.h"

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

	for (int i = 0; i < EventCount; ++i)
	{
		windowEvents[i] = false;
	}

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
		case SDL_QUIT:
			windowEvents[EventQuit] = true;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				App->window->Resize(event.window.data1, event.window.data2);
				break;
			case SDL_WINDOWEVENT_HIDDEN:
			case SDL_WINDOWEVENT_MINIMIZED:
			case SDL_WINDOWEVENT_FOCUS_LOST:

				windowEvents[EventHide] = true;
				break;

			case SDL_WINDOWEVENT_SHOWN:
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			case SDL_WINDOWEVENT_MAXIMIZED:
			case SDL_WINDOWEVENT_RESTORED:
				windowEvents[EventShow] = true;
				break;
			}

			break;
		case SDL_MOUSEBUTTONDOWN:
			mouseButtons[event.button.button - 1] = KeyState::KeyDown;
			break;
		case SDL_MOUSEBUTTONUP:
			mouseButtons[event.button.button - 1] = KeyState::KeyUp;
			break;
		case SDL_MOUSEMOTION:
			mousePosition.x = event.motion.x / SCREEN_SIZE;
			mousePosition.y = event.motion.y / SCREEN_SIZE;
			break;

		}
	}

	if (GetWindowEvent(EventWindow::EventQuit) == true)
		return UpdateState::UpdateStop;

	return UpdateState::UpdateContinue;
}

bool ModuleInput::CleanUp()
{
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}

bool ModuleInput::GetWindowEvent(EventWindow event) const
{
	return windowEvents[event];
}
