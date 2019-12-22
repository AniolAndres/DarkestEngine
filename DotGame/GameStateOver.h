#ifndef GAMESTATEOVER_H
#define GAMESTATEOVER_H

#include "GameState.h"

class GameStateOver :
	public GameState
{
public:
	GameStateOver(ModuleGame* game);
	~GameStateOver();

	void ChangeState() override;
	void Update() override;

	float timer = 0.0f;

	float duration = 5.0f;
};

#endif // GAMESTATEOVER_H