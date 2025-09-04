#pragma once
#include "grid.h"

class Simulation 
{
public:
	Simulation( int width, int height, int cell_size ) :
	game_grid( width, height, cell_size ), next_grid(width, height, cell_size) 
	{ game_grid.RandomStart(); };

	void Draw();
	void SetCellStatus(int row, int col, bool status);
	int CountLiveNeighbors(int row, int col);
	void Update();
	void ThreadedUpdate(int start, int end);

private:
	Grid game_grid;
	Grid next_grid;
};


