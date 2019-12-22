#ifndef GAMESTATEOVER_H
#define GAMESTATEOVER_H

#include "GameState.h"

class GameStateOver :
	public GameState
{
public:
	GameStateOver(ModuleGame* game);
	~GameStateOver();
};

#endif // GAMESTATEOVER_H