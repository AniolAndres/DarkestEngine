#ifndef GAMESTATEPLAYING_H
#define GAMESTATEPLAYING_H

#include "GameState.h"

class GameStatePlaying :
	public GameState
{
public:
	GameStatePlaying(ModuleGame* game);
	~GameStatePlaying();

	void ChangeState() override;
	void Update() override;

	int score = 0;
};

#endif // GAMESTATEPLAYING_H