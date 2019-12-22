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
	App->render->Draw(game->greenCircle, 0, 150, 4.0f, &game->rectangle64);

	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_SIZE; i += 16)
	{
		App->render->Draw(game->greenCircle, 50, i, 4.0f, &game->rectangle64);
	}
}
