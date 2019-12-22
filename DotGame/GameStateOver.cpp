#include "GameStateOver.h"

#include "Application.h"
#include "ModuleGame.h"
#include "ModuleTime.h"
#include "ModuleRender.h"

GameStateOver::GameStateOver(ModuleGame* game)
{
	this->game = game;
}


GameStateOver::~GameStateOver()
{
}

void GameStateOver::ChangeState()
{
	if (timer > duration)
	{
		game->currentState = (GameState*)game->play;
	}
	else
	{
		timer += App->time->deltaTime;
	}
}

void GameStateOver::Exit()
{
	timer = 0.0f;
}

void GameStateOver::Update()
{
	//Print GameOver and score
}

