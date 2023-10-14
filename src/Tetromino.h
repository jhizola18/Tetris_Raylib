#pragma once
#include <map>
#include <vector>
#include "Position.h"
#include "Colors.h"


class Tetromino {
private:


	int cellSize;
	int rotationState;
	std::vector<Color> colors;

	int rowOffset;
	int columnOffset;

public:
	Tetromino();
	int id;
	//this container is a map container 
	//it store the key and the value it holds

	std::map<int, std::vector<Position>> cells;
	void Draw(int offsetX, int offsetY);
	void Move(int rows, int columns);
	void Rotate();
	void UndoRotation();
	std::vector<Position> GetCellPos();
};
