#include "raylib.h"
#include "colors.h"
#include "resource_dir.h"
#include "game.h"
#include <iostream>

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime > interval) {
		lastUpdateTime = currentTime;
		return true;
	} else {
		return false;
	}
}

int main ()
{
	int width = 1260, height = 860;

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(width, height, "Snake");
	SearchAndSetResourceDir("resources");

	Game game = Game();

	// game loop
	while (!WindowShouldClose())
	{
		if (!game.gameOver) {
			game.snake.handleInput();
			if (eventTriggered(0.2)) {
				game.update();
			}
		} else if (IsKeyPressed(KEY_SPACE)) {
			game.restart();
		}

		// drawing
		BeginDrawing();
		ClearBackground(DARK_BLUE);

		game.draw();

		// UI
		int offsetX = 30;

		DrawRectangleLinesEx({(float)(width - 400), 20, 380, (float)(height - 30)}, 3, DARK_YELLOW);

		Vector2 scoreSize = MeasureTextEx(GetFontDefault(), "Score", 30, 1);
		DrawText("Score", (float)(width - 190 - offsetX - scoreSize.x /2), 40, 30, DARK_YELLOW);

		char scoreText[6] = {0};
		sprintf(scoreText, "%d", game.snake.score);
		Vector2 scoreTextSize = MeasureTextEx(GetFontDefault(), scoreText, 70, 1);
		DrawText(scoreText, (float)(width - 190 - offsetX - scoreTextSize.x /2), 100, 70, DARK_YELLOW);

		if (game.gameOver) {
			Vector2 gameOverSize = MeasureTextEx(GetFontDefault(), "Game Over", 50, 1);
			DrawText("Game Over", (float)(width - 190 - offsetX - gameOverSize.x /2), 320, 50, DARK_YELLOW);

			Vector2 restartSize = MeasureTextEx(GetFontDefault(), "Press Space to restart", 20, 1);
			DrawText("Press Space to restart", (float)(width - 190 - offsetX - restartSize.x /2), 400, 20, DARK_YELLOW);
		}


		EndDrawing();
	}

	CloseWindow();
	return 0;
}
