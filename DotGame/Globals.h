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
#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 176
#define SCREEN_SIZE 3
#define TITLE "DarkestEngine"


#define ROWS_NUMBER 11
#define COLUMS_NUMBER 10
#define MAXNUMBERS 11


#endif // GLOBALS_H
