#include "ModuleGame.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

ModuleGame::ModuleGame()
{
	//GreenCircle
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
	greenCircle = App->textures->Load("ClickableGreen.png");
	redCircle = App->textures->Load("ClickableRed.png");
	tileBackGround = App->textures->Load("TileBackground.png");
	tileMouseOver = App->textures->Load("TileMouseOver.png");

	return true;
}

UpdateState ModuleGame::Update()
{
	for (int i = 0; i < SCREEN_WIDTH*SCREEN_SIZE; i += 16)
	{
		App->render->Draw(greenCircle, i, 120, 4.0f, &rectangle64);
	}

	//for (int i = 0; i < SCREEN_HEIGHT*SCREEN_SIZE; i += 32)
	//{
	//	App->render->Draw(redCircle, 120, i, 2.0f, &rectangle64);
	//}

	//App->render->Draw(greenCircle, 150, 120, 2.0f, &rectangle64);
	//App->render->Draw(redCircle, 200, 200, 2.0f, &rectangle64);
	//App->render->Draw(tileBackGround, 50, 50, 2.0f, &rectangle64);
	//App->render->Draw(tileMouseOver, 50, 200, 2.0f, &rectangle64);

	return UpdateState::UpdateContinue;
}
