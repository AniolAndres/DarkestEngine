#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL_rect.h"

enum class MainStates
{
	Create,
	Init,
	Update,
	Finish,
	Exit
};

enum class UpdateState
{
	UpdateContinue,
	UpdateStop
};

// Configuration -----------
#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 224
#define SCREEN_SIZE 3
#define TITLE "DotGame"


#endif // GLOBALS_H
