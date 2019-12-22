#include "GameStatePlaying.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"
#include "ModuleInput.h"
#include "ModuleTime.h"

#include "Cell.h"
#include "Globals.h"
#include "Vector2.h"

GameStatePlaying::GameStatePlaying(ModuleGame * game)
{
	this->game = game;
}

GameStatePlaying::~GameStatePlaying()
{
}

void GameStatePlaying::ChangeState()
{
	if (end)
	{
		game->currentState = (GameState*)game->over;
	}
}

void GameStatePlaying::Enter()
{
	game->score = 0;

	//Set all tiles to be backGroundTiles

	for (int i = 0; i < COLUMS_NUMBER; ++i)
	{
		for (int j = 0; j < ROWS_NUMBER; ++j)
		{
			game->grid[i][j].state = CellState::Tile;
		}
	}

	//Set first row to be score
	for (int i = 0; i < COLUMS_NUMBER; ++i)
	{
		game->grid[i][0].isScore = true;
	}
}

void GameStatePlaying::Update()
{

	//if (App->input->GetMouseButtonDown(1) == KeyState::KeyDown)
	//{
	//}

	SpawnCircle();

	//MouseOver
	Vector2 mousePosition = App->input->GetMousePosition();
	mousePosition = mousePosition / 16.0f;

	int xTile = (int)mousePosition.x;
	int yTile = (int)mousePosition.y;

	//Grid drawing
	for (int i = 0; i < COLUMS_NUMBER; ++i)
	{
		for (int j = 0; j < ROWS_NUMBER; ++j)
		{
			float xPos = i * 16.0f;
			float yPos = j * 16.0f;

			if (i == xTile && j == yTile)
			{
				game->grid[i][j].DrawCell(game, xPos, yPos, true);
			}
			else
			{
				game->grid[i][j].DrawCell(game, xPos, yPos,false);
			}
			
		}
	}
}

void GameStatePlaying::SpawnCircle()
{
	if (circleSpawnTimer > timeBetweenCircles)
	{
		//SpawnCircle!
		spawnX = (rand() % 10); //We need +1 cause first row is score
		spawnY = rand() % 10 + 1;
		int circleColor = rand() % 2;

		switch (circleColor)
		{
			case 0:
				game->grid[spawnX][spawnY].state = CellState::Green;
				break;
			case 1:
				game->grid[spawnX][spawnY].state = CellState::Red;
				break;	
		}

		circleSpawned = true;
		circleSpawnTimer = 0.0f;
	}
	else
	{
		circleSpawnTimer += App->time->deltaTime;
	}

	if (circleSpawned)
	{
		if (clickTimer > timeToClick)
		{
			game->grid[spawnX][spawnY].state = CellState::Tile;
			circleSpawned = false;
			clickTimer = 0.0f;
		}
		else
		{
			clickTimer += App->time->deltaTime;
		}
	}
}
