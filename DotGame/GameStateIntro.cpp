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
	//Draw the intro text
	App->render->Draw(game->presentation, 30, SCREEN_HEIGHT * 0.4f, 9.0f, &game->presentRect);
}
