#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual void ChangeState() {}
	virtual void Enter() {}
	virtual void Update() {}
	virtual void Exit() {}
};

#endif // GAMESTATE_H