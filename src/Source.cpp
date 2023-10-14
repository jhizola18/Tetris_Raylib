#include "MainWindow.h"
#include "Game.h"
#include "Colors.h"

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
	double currTime = GetTime();
	if (currTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currTime;
		return true;
	}

	return false;
}

int main()
{
	const int screenHeight = 650;
	const int screenWidth = 500;

	Window window{screenWidth, screenHeight, 60, "Tetris"};

	Font font = LoadFontEx("fonts/TechnoFont", 64, 0, 0);
	
	Game game = Game();

	while (!window.gameShouldClose())
	{
		UpdateMusicStream(game.music);
		if (eventTriggered(0.25))
		{
			game.moveTetroDown();
		}
		game.playerInput();
		BeginDrawing();
		ClearBackground(BLUE);
		DrawTextEx(font, "Score: ", {365, 40}, 38, 2, WHITE);
		DrawTextEx(font, "Next: ", { 380, 160 }, 38, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 360, 450 }, 20, 2, WHITE);
		}
		DrawRectangleRounded({ 345, 80, 150, 60 }, 0.3, 6,LightBlue);
		DrawText(TextFormat(" %i",game.score),  375, 90, 30, WHITE);
		DrawRectangleRounded({ 345, 220, 150, 150 }, 0.3, 6, LightBlue);
		
		game.Draw();
		EndDrawing();
	}
	
	
	return 0;
}