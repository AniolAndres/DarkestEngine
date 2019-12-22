#ifndef CELL_H
#define CELL_H

class ModuleGame;

enum class CellState
{
	Nothing,
	Red,
	Green,
	Tile,
	Highlight
};

class Cell
{
public:
	Cell();
	~Cell();

	bool isScore = false;

	CellState state;
	void DrawCell(ModuleGame* game, float x, float y, bool mouseOver);

	float defaultSize = 4.0f;
};

#endif // 