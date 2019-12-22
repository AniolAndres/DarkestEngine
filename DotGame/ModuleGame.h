#ifndef MODULEGAME_H
#define MODULEGAME_H

#include "Module.h"
#include "Globals.h"
#include "Cell.h"

struct SDL_Texture;
struct SDL_Rect;
class GameState;
class GameStateIntro;
class GameStatePlaying;
class GameStateOver;

class ModuleGame : public Module
{
public:
	ModuleGame();
	~ModuleGame();

	bool Init() override;
	bool CleanUp() override;

	UpdateState Update() override;
	void LoadTextures();
public:

	int score = 0;

	GameState* currentState = nullptr;

	GameStateIntro* intro = nullptr;
	GameStatePlaying* play = nullptr;
	GameStateOver* over = nullptr;

	SDL_Texture* greenCircle = nullptr;
	SDL_Texture* redCircle = nullptr;
	SDL_Texture* tileBackGround = nullptr;
	SDL_Texture* tileMouseOver = nullptr;
	SDL_Texture* presentationP1 = nullptr;
	SDL_Texture* presentationP2 = nullptr;
	SDL_Texture* numbers = nullptr;

	SDL_Rect rectangle64;

	SDL_Rect presentRect1;
	SDL_Rect presentRect2;

	SDL_Rect number0;
	SDL_Rect number1;
	SDL_Rect number2;
	SDL_Rect number3;
	SDL_Rect number4;
	SDL_Rect number5;
	SDL_Rect number6;
	SDL_Rect number7;
	SDL_Rect number8;
	SDL_Rect number9;
	SDL_Rect number10;

	Cell grid[COLUMS_NUMBER][ROWS_NUMBER];

private:

	void CheckStates(GameState* previous);
};

#endif // MODULEEGAME_H