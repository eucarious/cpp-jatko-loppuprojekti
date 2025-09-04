#include <vector>
#include <utility>
#include <thread>
#include <future>
#include "simulation.h"


/*! Calls the grid's draw function.
*
*/
void Simulation::Draw()
{
	game_grid.Draw();
}

/*! Sets the cell's status with the grid's SetStatus function.
*	@param row the row the cell is on.
*	@param col the column the cell is on.
*	@param status whether the cell is dead or alive.
*/
void Simulation::SetCellStatus(int row, int col, bool status)
{
	game_grid.SetStatus(row, col, status);
}

/*! Counts the adjacent cells that are alive. Includes diagonals.
*	@param row the row the cell is on.
*	@param col the column the cell is on.
*	@return returns the amount of adjacent cells that are alive
*/
int Simulation::CountLiveNeighbors(int row, int col)
{
	int living_neighbors = 0; /*! Total living cells around the cell entered.*/
	//... i couldve used this for chess. I COULDVE USED THIS FOR CHEEEESSSSSS
	std::vector<std::pair<int, int>> offsets{
	{ -1, -1 },	{ 0, -1 }, { 1, -1 },
	{ -1, 0 },				{ 1, 0 },
	{ -1, 1 },	{ 0, 1 },	{ 1, 1 }
	};

	for (int i = 0; i < 8; i++) 
	{
		int neighborRow = row + offsets.at(i).first;
		int neighborCol = col + offsets.at(i).second;

		living_neighbors = game_grid.GetStatus(neighborRow, neighborCol) ? living_neighbors + 1 : living_neighbors;
	}

	return living_neighbors;
}


/*! Updates the game every frame. Currently used to call the threaded update to meet final project submission requirements
*
*/
void Simulation::Update()
{
	// the functionality for update if this wasn't threaded
	//for (int row = 0; row < game_grid.GetRows(); row++)
	//{
	//	for (int col = 0; col < game_grid.GetCols(); col++)
	//	{
	//		/*!
	//		*/
	//		int living_neighbors = CountLiveNeighbors(row, col);
	//		bool cell_status = game_grid.GetStatus(row, col);
	//		if (cell_status) {
	//			if (living_neighbors < 2 || living_neighbors > 3)
	//			{
	//				next_grid.SetStatus(row, col, false);
	//			}
	//			else
	//			{
	//				next_grid.SetStatus(row, col, true);
	//			}
	//		}
	//		else
	//		{
	//			if (living_neighbors == 3)
	//			{
	//				next_grid.SetStatus(row, col, true);
	//			}
	//			else
	//			{
	//				next_grid.SetStatus(row, col, false);
	//			}
	//		}
	//	}
	//}


	int row_division = game_grid.GetRows() / 5;
	
	std::thread one(&Simulation::ThreadedUpdate, this, 0, row_division);
	std::thread two(&Simulation::ThreadedUpdate, this, row_division, row_division * 2);
	std::thread three(&Simulation::ThreadedUpdate, this, row_division * 2, row_division * 3);
	std::thread four(&Simulation::ThreadedUpdate, this, row_division * 3, row_division * 4);
	std::thread five(&Simulation::ThreadedUpdate, this, row_division * 4, row_division * 5);
	//std::thread six(&Simulation::ThreadedUpdate, this, row_division * 5, row_division * 6);
	//std::thread seven(&Simulation::ThreadedUpdate, this, row_division * 6, row_division * 7);
	//std::thread eight(&Simulation::ThreadedUpdate, this, row_division * 7, row_division * 8);
	
	one.join();
	two.join();
	three.join();
	four.join();
	five.join();
	//six.join();
	//seven.join();
	//eight.join();

	game_grid = next_grid;

}

/*! A Threadable version of the Update function. 
*	@param start from which row the loop will start from.
*	@param end which row to stop before.
*/
void Simulation::ThreadedUpdate(int start, int end) 
{
	for (int row = start; row < end; row++)
	{
		for (int col = 0; col < game_grid.GetCols(); col++)
		{
			/*! 
			*/
			int living_neighbors = CountLiveNeighbors(row, col);
			bool cell_status = game_grid.GetStatus(row, col);

			if (cell_status) {

				if (living_neighbors < 2 || living_neighbors > 3)
				{
					next_grid.SetStatus(row, col, false);
				}
				else
				{
					next_grid.SetStatus(row, col, true);
				}

			}
			else
			{
				if (living_neighbors == 3)
				{
					next_grid.SetStatus(row, col, true);
				}
				else
				{
					next_grid.SetStatus(row, col, false);
				}
			}
		}
	}
}