#include "GameStatePlaying.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"

#include "Globals.h"

GameStatePlaying::GameStatePlaying(ModuleGame * game)
{
	this->game = game;
}

GameStatePlaying::~GameStatePlaying()
{
}

void GameStatePlaying::ChangeState()
{
}

void GameStatePlaying::Update()
{
	for (int i = 0; i < ROWS_NUMBER; ++i)
	{
		for (int j = 0; j < COLUMS_NUMBER; ++j)
		{
			App->render->Draw(game->tileBackGround, i * 16, j * 16, 4.0f, &game->rectangle64);
		}
	}
}
