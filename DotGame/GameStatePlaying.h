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
	void Enter() override;
	void Update() override;

	bool end = false;
};

#endif // GAMESTATEPLAYING_H