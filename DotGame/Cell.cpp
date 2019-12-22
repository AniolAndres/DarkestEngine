#include "Cell.h"

#include "Application.h"
#include "ModuleRender.h"
#include "ModuleGame.h"

Cell::Cell()
{
}


Cell::~Cell()
{
}

void Cell::DrawCell(ModuleGame* game, float x, float y, bool mouseOver)
{
	if (!isScore)
	{
		switch (state)
		{
		case CellState::Nothing:
			//Nothing to draw
			break;
		case CellState::Red:
			App->render->Draw(game->redCircle, x, y, defaultSize, &game->rectangle64);
			break;
		case CellState::Green:
			App->render->Draw(game->greenCircle, x, y, defaultSize, &game->rectangle64);
			break;
		case CellState::Tile:
			App->render->Draw(game->tileBackGround, x, y, defaultSize, &game->rectangle64);
			break;
		}

		if (mouseOver)
		{
			App->render->Draw(game->tileMouseOver, x, y, defaultSize, &game->rectangle64);
		}
	}
}
