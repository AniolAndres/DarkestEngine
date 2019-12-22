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
	presentRect1.x = 0;
	presentRect1.y = 0;
	presentRect1.w = 1377;
	presentRect1.h = 313;

	presentRect2.x = 0;
	presentRect2.y = 0;
	presentRect2.w = 878;
	presentRect2.h = 156;

	//Numbers will have same widths and heights but they all will have their own
	number0.x = 1100;
	number0.y = 0;
	number0.h = 130;
	number0.w = 80;

	number1.x = 0;
	number1.y = 0;
	number1.h = 130;
	number1.w = 117;

	number2.x = 117;
	number2.y = 0;
	number2.h = 130;
	number2.w = 117;

	number3.x = 220;
	number3.y = 0;
	number3.h = 130;
	number3.w = 117;

	number4.x = 320;
	number4.y = 0;
	number4.h = 130;
	number4.w = 117;


	number5.x = 430;
	number5.y = 0;
	number5.h = 130;
	number5.w = 117;

	number6.x = 540;
	number6.y = 0;
	number6.h = 130;
	number6.w = 117;

	number7.x = 650;
	number7.y = 0;
	number7.h = 130;
	number7.w = 117;

	number8.x = 760;
	number8.y = 0;
	number8.h = 130;
	number8.w = 117;

	number9.x = 870;
	number9.y = 0;
	number9.h = 130;
	number9.w = 117;

	number10.x = 1000;
	number10.y = 0;
	number10.h = 130;
	number10.w = 170;
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
	presentationP1 = App->textures->Load("AniolPresents.png");
	presentationP2 = App->textures->Load("TheDotGame.png");
	numbers = App->textures->Load("numbers.png");
}

void ModuleGame::CheckStates(GameState * previous)
{
	if (currentState != previous)
	{
		previous->Exit();
		currentState->Enter();
	}
}
