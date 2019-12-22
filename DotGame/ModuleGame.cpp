#include "ModuleGame.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

#include "GameState.h"
#include "GameStateIntro.h"
#include "GameStateOver.h"
#include "GameStatePlaying.h"

#include "Vector2.h"

ModuleGame::ModuleGame()
{
	//All png given in assets are 64x64 so we only need one SDL rect
	rectangle64.x = 0;
	rectangle64.y = 0;
	rectangle64.w = 64;
	rectangle64.h = 64;

	//Texts will have each its own rectangle
	presentRect.x = 0;
	presentRect.y = 0;
	presentRect.w = 864;
	presentRect.h = 176;

	//GameOver Text
	gameOverRect.x = 0;
	gameOverRect.y = 0;
	gameOverRect.w = 1475;
	gameOverRect.h = 131;

	//Numbers will have same widths and heights but they all will have their own
	numberRectangles[0].x = 1100;
	numberRectangles[0].y = 0;
	numberRectangles[0].h = 130;
	numberRectangles[0].w = 80;

	numberRectangles[1].x = 0;
	numberRectangles[1].y = 0;
	numberRectangles[1].h = 130;
	numberRectangles[1].w = 117;

	numberRectangles[2].x = 117;
	numberRectangles[2].y = 0;
	numberRectangles[2].h = 130;
	numberRectangles[2].w = 117;

	numberRectangles[3].x = 220;
	numberRectangles[3].y = 0;
	numberRectangles[3].h = 130;
	numberRectangles[3].w = 117;

	numberRectangles[4].x = 320;
	numberRectangles[4].y = 0;
	numberRectangles[4].h = 130;
	numberRectangles[4].w = 117;

	numberRectangles[5].x = 430;
	numberRectangles[5].y = 0;
	numberRectangles[5].h = 130;
	numberRectangles[5].w = 117;

	numberRectangles[6].x = 540;
	numberRectangles[6].y = 0;
	numberRectangles[6].h = 130;
	numberRectangles[6].w = 117;

	numberRectangles[7].x = 650;
	numberRectangles[7].y = 0;
	numberRectangles[7].h = 130;
	numberRectangles[7].w = 117;

	numberRectangles[8].x = 760;
	numberRectangles[8].y = 0;
	numberRectangles[8].h = 130;
	numberRectangles[8].w = 117;

	numberRectangles[9].x = 870;
	numberRectangles[9].y = 0;
	numberRectangles[9].h = 130;
	numberRectangles[9].w = 117;

	numberRectangles[10].x = 1000;
	numberRectangles[10].y = 0;
	numberRectangles[10].h = 130;
	numberRectangles[10].w = 170;
}


ModuleGame::~ModuleGame()
{
}

bool ModuleGame::Init()
{
	intro = new GameStateIntro(this);
	play = new GameStatePlaying(this);
	over = new GameStateOver(this);

	currentState = intro;

	LoadTextures();

	return true;
}

bool ModuleGame::CleanUp()
{
	//Erase states
	delete intro;
	intro = nullptr;
	delete play;
	play = nullptr;
	delete over;
	over = nullptr;

	return false;
}

UpdateState ModuleGame::Update()
{
	
	GameState* previous = currentState;

	//This will check state changes
	currentState->ChangeState();

	//if there is a change Exit and Enter will e called
	CheckStates(previous);

	//Takes care of the draw calls
	currentState->Update();

	return UpdateState::UpdateContinue;
}

void ModuleGame::LoadTextures()
{
	greenCircle = App->textures->Load("ClickableGreen.png");
	redCircle = App->textures->Load("ClickableRed.png");
	tileBackGround = App->textures->Load("TileBackground.png");
	tileMouseOver = App->textures->Load("TileMouseOver.png");
	presentation = App->textures->Load("Presentation.png");
	numbers = App->textures->Load("numbers.png");
	gameOver = App->textures->Load("GameOver.png");
}

void ModuleGame::CheckStates(GameState * previous)
{
	if (currentState != previous)
	{
		previous->Exit();
		currentState->Enter();
	}
}
