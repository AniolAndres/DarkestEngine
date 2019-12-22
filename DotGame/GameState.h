#ifndef GAMESTATE_H
#define GAMESTATE_H

class ModuleGame;

class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual void ChangeState() {}
	virtual void Enter() {}
	virtual void Update() {}
	virtual void Exit() {}

	ModuleGame* game = nullptr;
};

#endif // GAMESTATE_H