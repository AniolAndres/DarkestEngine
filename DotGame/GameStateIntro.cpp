#include "GameStateIntro.h"

#include "Application.h"
#include "ModuleTime.h"
#include "ModuleGame.h"
#include "ModuleRender.h"

GameStateIntro::GameStateIntro(ModuleGame * game)
{
	this->game = game;
}

GameStateIntro::~GameStateIntro()
{
}

void GameStateIntro::ChangeState()
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

void GameStateIntro::Update()
{
	App->render->Draw(game->greenCircle, 150, 150, 2.0f, &game->rectangle64);
}
