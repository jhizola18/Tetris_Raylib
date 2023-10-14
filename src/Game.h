#pragma once
#include "Board.h"
#include "Tetrominoes.cpp"


class Game {
private:
	Board board;

	std::vector<Tetromino> tetros;
	Tetromino currTetro;
	Tetromino nextTetro;
	bool isTetroOutside();
	void lockTetro();
	bool tetroFits();
	void reset();
	void updateScore(int lineCleared, int moveDownPoint);
	Tetromino GetRandomTetro();
	std::vector<Tetromino> GetAllTetro();
	void moveTetroLeft();
	void moveTetroRight();
	Sound clearSound;
	Sound rotateSound;

public:
	Game();
	~Game() noexcept;

	void Draw();
	void playerInput();
	void moveTetroDown();
	void rotateTetro();
	bool gameOver;
	int score;
	
	Music music;

};