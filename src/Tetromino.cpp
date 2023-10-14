#include "Tetromino.h"

Tetromino::Tetromino()
{
	cellSize = 30;
	rotationState = 0;
	colors = getCellColors();
	rowOffset = 0;
	columnOffset = 0;
}


void Tetromino::Draw(int offsetX, int offsetY)
{
	std::vector<Position> tiles = GetCellPos();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

//This function takes an arguement of row and column which the value will be added to 
//the offset where it's initialized once the tetromino class has been instantiate;
void Tetromino::Move(int rows, int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

void Tetromino::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
	{
		rotationState = 0;
	}
}

void Tetromino::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = cells.size() - 1;
	}
}


//This container is to check the position that the tetromino occupying 
//and returning the current position of the tetromino
//with the offset variable we are able to move the tetromino in a certain position
std::vector<Position> Tetromino::GetCellPos()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		//because of the offset we were able to manipulate the tetrominoes cells one by one
		//positioning
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}

	return movedTiles;

}