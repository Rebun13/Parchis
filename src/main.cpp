#include <memory>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "raylib.h"
#include "./core/colors.h"
#include "./core/game.h"
#include "style/styleLoader.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

void loadingScreen(Font font);

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	// SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(480, 720, "Parchix");
	SetTargetFPS(60);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	GuiLoadStyleDark();
	Font font = LoadFont("fonts/JetSet-8j1J.ttf");

	loadingScreen(font);

	Game game = Game();
	game.state_ = &Game::menu;
	game.state_->init();

	// game loop
	while (!(WindowShouldClose() || game.gameShouldClose())) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// Handle input
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			// Vector2 touchPoint = GetTouchPosition(0);
			Vector2 touchPoint = GetMousePosition();
			game.handleInput(touchPoint);
		}

		// Update

		// drawing
		BeginDrawing();
		ClearBackground(bgColor);
		// Draw game
		game.draw();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	};

	// cleanup
	UnloadFont(font);
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void loadingScreen(Font font)
{
	float elapsedTime = 0;
	unsigned char opacity = 0;

	while (elapsedTime < 6.0f)
	{
		elapsedTime += GetFrameTime();

		if (elapsedTime >= 1 && elapsedTime <= 2)
		{
			opacity = std::round(255.0f * (elapsedTime - 1));
		}
		else if (elapsedTime >= 5)
		{
			opacity = std::round(255.0f * (6.0f - elapsedTime));
		}

		Color color = {255, 255, 255, opacity};
		BeginDrawing();
		ClearBackground(bgColor);
		DrawTextEx(font, "PARCHIS", {107, 220}, 90, 5, color);
		DrawTextEx(font, "Estudio CEIVE", {151, 600}, 35, 5, color);
		DrawTextEx(font, "by Rebun", {205, 645}, 20, 5, color);
		EndDrawing();
	}
}