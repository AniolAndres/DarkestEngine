#ifndef MODULEINPUT_H
#define MODULEINPUT_H

#include "Module.h"

#include "Vector2.h"

#define NUM_MOUSE_BUTTONS 5
#define NUM_WINDOW_EVENTS 3

enum class KeyState
{
	KeyIdle,
	KeyDown,
	KeyUp,
	KeyRepeat
};

enum class EventWindow
{
	EventQuit,
	EventHide,
	EventShow
};

class ModuleInput :
	public Module
{
public:
	ModuleInput();
	~ModuleInput();

	bool Init() override;
	UpdateState PreUpdate() override;
	bool CleanUp() override;

	bool GetWindowEvent(EventWindow event) const;

private:
	bool windowEvents[NUM_WINDOW_EVENTS];

	Vector2 mousePosition;
	KeyState mouseButtons[NUM_MOUSE_BUTTONS];
};

#endif // MODULEINPUT_H