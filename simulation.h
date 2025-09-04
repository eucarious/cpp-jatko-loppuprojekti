#pragma once
#include "grid.h"

class Simulation 
{
public:

	/*! The one and only simulation constructor. 
	*	All parameters are passed forward to the Grid constructor.
	*	The grid is also populated with a random start of living cells.
	*	@param width the width of the window.
	*	@param height the height of the window.
	*	@param cell_size size of one cell in pixels. Minimum size of 2 pixels
	*/
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


