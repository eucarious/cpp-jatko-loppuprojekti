#pragma once
#include <vector>

/*! The grid that the game of life will happen on
* 
*/
class Grid 
{
public:


	/*! The one and only grid constructor
	*	@param width the width of the window.
	*	@param height the height of the window.
	*	@param cell_size size of one cell in pixels. Minimum size of 2 pixels
	*/
	Grid(int width, int height, int cell_size): 
		rows(height / cell_size),
		cols(width / cell_size),
		cell_size(cell_size),
		cells(rows, std::vector<bool>(cols, 0)) {}; /*! Initialize the cells variable. Initialize 'rows' amount of boolean vectors, which all have 'cols' amount of members, all initialized as 0 */

	void Draw();

	int GetRows();
	int GetCols();

	void SetStatus(int row, int col, bool status);
	bool GetStatus(int row, int col);
	bool IsInBounds(int row, int col);

	void RandomStart();

private:
	int rows, cols, cell_size;

	/*! A vector of bool vectors, so a matrix 
	*/
	std::vector<std::vector<bool>> cells;
};