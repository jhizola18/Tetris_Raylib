#include "Board.h"
#include <iostream>
#include "Colors.h"

Board::Board()
{
	//Dimension of the board
	rowsNum = 20;
	columnsNum = 10;
	//size of the pixel;
	cellsize = 30;
	initializeBoard();
	colors = getCellColors();
	
};

//Putting a 0 value inside the 2D array that we created
void Board::initializeBoard()
{
	for (int row = 0; row < rowsNum; ++row)
	{
		for (int col = 0; col < columnsNum; ++col)
		{
			grid[row][col] = 0;
		}
	}
}


bool Board::isRowFull(int row)
{
	for (int col = 0; col < columnsNum; ++col)
	{
		if (grid[row][col] == 0)
		{
			return false;
		}
	}

	return true;
}

void Board::clearRow(int row)
{
	for (int col = 0; col < columnsNum; ++col)
	{
		grid[row][col] = 0;
	}
}

void Board::moveDownRow(int row, int numRows)
{
	for (int col = 0; col < columnsNum; ++col)
	{
		grid[row + numRows][col] = grid[row][col];
		grid[row][col] = 0;

	}
}



//Drawing the board by drawing small rectangles/cells that will scale according to the given row number and column number
//+ 1 for the x and y position to give a little space to the sorrounding of the board
//and - 1 for the height and width of the small rectangles to see the gap in between the cells
void Board::drawBoard()
{
	for (int row = 0; row < rowsNum; ++row)
	{
		for (int col = 0; col < columnsNum; ++col)
		{
			int cellValue = grid[row][col];
			DrawRectangle(col  * cellsize + 30, row * cellsize + 30, cellsize - 1, cellsize - 1, colors[cellValue]);
		}
	}
}

//This boolean is used to check if the cell of the tetrominoes is outside the board
bool Board::isCellOutSide(int row, int column)
{
	if (row >= 0 && row < rowsNum && column >= 0 && column < columnsNum)
	{
		return false;
	}

	return true;
}

//This is to clear a row that is full
//and dropping down the above row fill with cell
//
int Board::clearFullRows()
{
	int completed = 0;
	for (int row = rowsNum - 1; row >=0; row--)
	{
		if (isRowFull(row))
		{
			clearRow(row);
			completed++;
		}
		else if (completed > 0)
		{
			moveDownRow(row, completed);
		}
	}

	return completed;
}

//To check if the cell are empty if empty it will return true
//this checker checks the rows and columns
bool Board::isCellEmpty(int row, int column)
{
	if (grid[row][column] == 0) 
	{
		return true;
	}
	return false;
}


