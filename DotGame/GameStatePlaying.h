#ifndef GAMESTATEPLAYING_H
#define GAMESTATEPLAYING_H

#include "GameState.h"

class GameStatePlaying :
	public GameState
{
public:
	GameStatePlaying(ModuleGame* game);
	~GameStatePlaying();
};

#endif // GAMESTATEPLAYING_H