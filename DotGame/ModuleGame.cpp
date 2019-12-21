#include "ModuleGame.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"

ModuleGame::ModuleGame()
{
	//GreenCircle
	greenCircleRectangle.x = 0;
	greenCircleRectangle.y = 0;
	greenCircleRectangle.w = 64;
	greenCircleRectangle.h = 64;
}


ModuleGame::~ModuleGame()
{
}

bool ModuleGame::Init()
{
	greenCircle = App->textures->Load("ClickableGreen.png");

	return true;
}

UpdateState ModuleGame::Update()
{
	App->render->Draw(greenCircle, 150, 120, &greenCircleRectangle);

	return UpdateState::UpdateContinue;
}
