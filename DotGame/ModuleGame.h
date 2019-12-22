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
	
private:

	void CheckStates(GameState* previous);
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
	SDL_Texture* presentation = nullptr;
	SDL_Texture* numbers = nullptr;
	SDL_Texture* gameOver = nullptr;

	SDL_Rect rectangle64;
	SDL_Rect presentRect;
	SDL_Rect gameOverRect;

	SDL_Rect numberRectangles[MAXNUMBERS];

	Cell grid[COLUMS_NUMBER][ROWS_NUMBER];

};

#endif // MODULEEGAME_H