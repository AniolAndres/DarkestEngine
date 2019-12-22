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
	//App->render->Draw(game->presentationP1, 10, (SCREEN_HEIGHT / 8) * SCREEN_SIZE , 10.0f, &game->presentRect1);

	//App->render->Draw(game->presentationP1, 10, (SCREEN_HEIGHT / 8) * SCREEN_SIZE, 10.0f, &game->presentRect1);

	App->render->Draw(game->numbers, 10, (SCREEN_HEIGHT / 8) * SCREEN_SIZE, 10.0f, &game->number0);

}
