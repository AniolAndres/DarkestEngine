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
	App->render->Draw(game->gameOver, SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.45f, 12.0f, &game->gameOverRect);

	App->render->Draw(game->numbers, SCREEN_WIDTH * 0.89f, SCREEN_HEIGHT * 0.45f, 10.0f, &game->numberRectangles[game->score]);
}

