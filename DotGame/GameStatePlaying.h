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

	void ResetVariables();
	void CellHasBeenClicked(int x, int y);

	void SpawnCircle();

	bool end = false;

	bool clickedRight = false;
	bool clickedLeft = false;

	bool circleSpawned = false;
	int spawnX = 0;
	int spawnY = 0;

	float clickTimer = 0.0f;
	float circleSpawnTimer = 0.0f;

	float timeBetweenCircles = 3.0f;
	float timeToClick = 1.5f;
};

#endif // GAMESTATEPLAYING_H