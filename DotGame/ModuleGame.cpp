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
}

void ModuleGame::CheckStates(GameState * previous)
{
	if (currentState != previous)
	{
		previous->Exit();
		currentState->Enter();
	}
}
