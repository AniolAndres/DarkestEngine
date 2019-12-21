#ifndef MODULEINPUT_H
#define MODULEINPUT_H

#include "Module.h"

#include "Vector2.h"

#define NUM_MOUSE_BUTTONS 5

enum class KeyState
{
	KeyIdle,
	KeyDown,
	KeyUp,
	KeyRepeat
};

enum EventWindow
{
	EventQuit = 0,
	EventHide,
	EventShow,
	EventCount
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
	bool windowEvents[EventCount];

	Vector2 mousePosition;
	KeyState mouseButtons[NUM_MOUSE_BUTTONS];
};

#endif // MODULEINPUT_H