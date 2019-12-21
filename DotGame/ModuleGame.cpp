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
	App->render->Draw(greenCircle, 150, 120, 5.0f, &rectangle64);
	App->render->Draw(redCircle, 200, 200, 5.0f, &rectangle64);
	App->render->Draw(tileBackGround, 50, 50, 5.0f, &rectangle64);
	App->render->Draw(tileMouseOver, 50, 200, 5.0f, &rectangle64);

	return UpdateState::UpdateContinue;
}
