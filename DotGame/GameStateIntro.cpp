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
	App->render->Draw(game->presentation, 30, SCREEN_HEIGHT / 2.5f, 9.0f, &game->presentRect);

	//App->render->Draw(game->numbers, 10, (SCREEN_HEIGHT / 8) * SCREEN_SIZE, 10.0f, &game->number0);

}
