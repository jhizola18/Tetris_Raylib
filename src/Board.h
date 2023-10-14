#pragma once
#include "raylib.h"
#include <vector>


class Board {
private:
	int rowsNum;
	int columnsNum;
	//size of the cell of the grid in each pixels;
	int cellsize;
	//This is to hold the cells that will represent the board;
	
	//This vector is to handle the container filled with colors
	std::vector<Color> colors;

	bool isRowFull(int row);
	void clearRow(int row);
	void moveDownRow(int row, int numRows);
	
	

public:
	//constructor
	Board();
	
	void initializeBoard();

	void drawBoard();

	bool isCellOutSide(int row, int column);

	bool isCellEmpty(int row, int column);

	int clearFullRows();
	//This is the 2D array that we used for creating the board
	int grid[20][10];
	
};
