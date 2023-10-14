#include "Game.h"
#include <random>

bool Game::isTetroOutside()
{
	std::vector<Position> tiles = currTetro.GetCellPos();
	for (Position item : tiles)
	{
		if (board.isCellOutSide(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

Game::Game()
{
	board = Board();
	tetros = GetAllTetro();
	currTetro = GetRandomTetro();
	nextTetro = GetRandomTetro();
	gameOver = false;
	score = 0;
	InitAudioDevice();
	music = LoadMusicStream("sfx/music.mp3");
	PlayMusicStream(music);
	rotateSound = LoadSound("sfx/rotate.mp3");
	clearSound = LoadSound("sfx/clear.mp3");
}

Game::~Game() noexcept
{
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadMusicStream(music);
	CloseAudioDevice();
}

//Generate or spawn random tetrominoes
//storing all tetrominoes inside the tetros variable
Tetromino Game::GetRandomTetro()
{
	if (tetros.empty())
	{
		tetros = GetAllTetro();
	}
	int randomBlock = rand() % tetros.size();
	Tetromino Tetro = tetros[randomBlock];
	tetros.erase(tetros.begin() + randomBlock);
	return Tetro;
}

//this is the container for storing all the Tetrominoes
std::vector<Tetromino> Game::GetAllTetro()
{
	return { ITetro(), JTetro(), ZTetro(), LTetro(), OTetro(), STetro(), TTetro() };
}

//Draw inside the board and the tetromino
void Game::Draw()
{
	board.drawBoard();
	currTetro.Draw(30, 30);
	switch (nextTetro.id)
	{
	case 3:
		nextTetro.Draw(275, 280);
		break;
	case 4:
		nextTetro.Draw(270, 260);
		break;
	default:
		nextTetro.Draw(280, 260);
		break;
	}
}


void Game::playerInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveTetroLeft();
		break;

	case KEY_RIGHT:
		moveTetroRight();
		break;

	case KEY_DOWN:
		moveTetroDown();
		updateScore(0, 1);
		break;

	case KEY_UP:
		rotateTetro();
		break;
	}
}


void Game::moveTetroLeft()
{
	if (!gameOver)
	{
		currTetro.Move(0, -1);
		if (isTetroOutside() || tetroFits() == false)
		{
			currTetro.Move(0, 1);
		}
	}
	

}

void Game::moveTetroRight()
{
	if (!gameOver)
	{
		currTetro.Move(0, 1);
		if (isTetroOutside() || tetroFits() == false)
		{
			currTetro.Move(0, -1);
		}
	}
	
}

void Game::moveTetroDown()
{
	if (!gameOver)
	{
		currTetro.Move(1, 0);
		if (isTetroOutside() || tetroFits() == false)
		{
			currTetro.Move(-1, 0);
			lockTetro();
		}
	}
	
}

void Game::rotateTetro()
{
	if (!gameOver)
	{
		currTetro.Rotate();
		if (isTetroOutside() || tetroFits() == false)
		{
			currTetro.UndoRotation();
		}
		
		PlaySound(rotateSound);
		
	}
	
}


void Game::lockTetro()
{
	std::vector<Position> tiles = currTetro.GetCellPos();
	for (Position item : tiles)
	{
		board.grid[item.row][item.column] = currTetro.id;
	}

	currTetro = nextTetro;
	if (tetroFits() == false)
	{
		gameOver = true;
	};
	nextTetro = GetRandomTetro();
	int rowsCleared = board.clearFullRows();
	if (rowsCleared > 0)
	{
		PlaySound(clearSound);
		updateScore(rowsCleared, 0);
	}
	
}


//We are going to get the current tetromino and we're iterating to all its cell 
//and check if their current position has been occupied by other tetromino
bool Game::tetroFits()
{
	std::vector<Position> tiles = currTetro.GetCellPos();
	for (Position item : tiles)
	{
		if (board.isCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}

	return true;
}

void Game::reset()
{
	board.initializeBoard();
	tetros = GetAllTetro();
	currTetro = GetRandomTetro();
	nextTetro = GetRandomTetro();
	score = 0;
}

void Game::updateScore(int lineCleared, int moveDownPoint)
{
	switch (lineCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 200;
		break;
	case 3:
		score += 300;
		break;
	default:
		break;
	}

	score += moveDownPoint;
}
