#include <raylib.h>
#include "grid.h"


/*! Draw each cell in the grid. Changes the color depending on whether the cell is dead or alive
*
*/
void Grid::Draw()
{
	for (int row = 0; row < rows; row++) 
	{
		for (int col = 0; col < cols; col++)
		{
			/*! Cell status changes color depending on whether the cell is Dead or Alive (0, 1).
			*	Variable cells[row][col] returns either true or false, making this possible
			*/
			Color cell_status = cells[row][col] ? Color{ 85, 85, 240, 255 } : Color{ 35, 35, 40, 255 };
			DrawRectangle(col * cell_size, row * cell_size, cell_size - 1, cell_size - 1, cell_status);
		}
	}
}

/*! Get the amount of rows in the grid
*	@return row amount
*/
int Grid::GetRows()
{
	return rows;
}

/*! Get the amount of columns in the grid
*	@return column amount
*/
int Grid::GetCols()
{
	return cols;
}


/*! Set a specific cell's value to either Dead or Alive 
*	@param row the row the cell is on.
*	@param col the column the cell is on.
*	@param status whether the cell is dead or alive.
*/
void Grid::SetStatus(int row, int col, bool status)
{
	if (IsInBounds(row, col))
		cells[row][col] = status; 
}

/*! Check whether a cell is Dead or Alive
*	@param row the row the cell is on.
*	@param col the column the cell is on.
*	@return returns false if the cell is dead, true if it is alive.
*/
bool Grid::GetStatus(int row, int col)
{
	if (IsInBounds(row, col))
		return cells[row][col];
	return false;
}

/*! Validate the given values by checking if the cell is in the bounds of the grid
*	@param row the row the cell is on.
*	@param col the column the cell is on.
*	@return returns true if the cell is within bounds, false if it is not.
*/
bool Grid::IsInBounds(int row, int col)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols)
		return true;
	return false;
}


/*! Randomize the grid's start. Currently has a 1/3 chance that a cell starts off alive.
*	
*/
void Grid::RandomStart()
{
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			int randomizerValue = GetRandomValue(0, 10);
			cells[row][col] = randomizerValue < 4 ? true : false; 
		}
	}
}