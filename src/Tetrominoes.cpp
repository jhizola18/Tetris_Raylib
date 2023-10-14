#include "Tetromino.h"
#include "Position.h"

class  LTetro : public Tetromino
{

public:
	LTetro(){
		id = 1;
		cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
		cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};

class JTetro : public Tetromino
{
public:
	JTetro() {
		id = 2;
		cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
		cells[3] = { Position(2,0), Position(2,1), Position(1,1), Position(0,1) };
		Move(0, 3);
	}

};


class ITetro : public Tetromino
{
public:
	ITetro() {
		id = 3;
		cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
		cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
		cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
		cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
		Move(-1, 3);
	}
	
};


class OTetro : public Tetromino
{
public:
	OTetro()
	{
		id = 4;
		cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[2] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		cells[3] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };
		Move(0, 4);
	}
};

class STetro : public Tetromino
{
public:
	STetro()
	{
		id = 5;
		cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
		cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
		cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};

class TTetro : public Tetromino
{
public:
	TTetro()
	{
		id = 6;
		cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
		cells[3] = { Position(1,0), Position(0,1), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};

class ZTetro : public Tetromino
{
public:
	ZTetro()
	{
		id = 7;
		cells[0] = { Position(0,0),Position(0,1),Position(1,1),Position(1,2) };
		cells[1] = { Position(0,2),Position(1,1),Position(1,2),Position(2,1) };
		cells[2] = { Position(1,0),Position(1,1),Position(2,1),Position(2,2) };
		cells[3] = { Position(0,1),Position(1,0),Position(1,1),Position(2,0) };
		Move(0, 3);
		
	}
};