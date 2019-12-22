#ifndef GAMESTATEINTRO_H
#define GAMESTATEINTRO_H

#include "GameState.h"

class GameStateIntro : public GameState
{
public:
	GameStateIntro(ModuleGame* game);
	~GameStateIntro();

	void ChangeState() override;
	void Update() override;

	float timer = 0.0f;
	float duration = 1.0f;
};

#endif // GAMESTATEINTRO_H