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
	unsigned char opacity = 0;

	Vector2 sizeA = MeasureTextEx(font, "PARCHIS", 90, 5);
	Vector2 sizeB = MeasureTextEx(font, "Estudio CEIVE", 35, 5);
	Vector2 sizeC = MeasureTextEx(font, "by Rebun", 20, 5);

	float animationDuration = 3.5f;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime())
	{
		if (elapsedTime >= 1 && elapsedTime <= 2)
		{
			opacity = std::round(255.0f * (elapsedTime - 1));
		}
		else if (elapsedTime >= animationDuration - 1.f)
		{
			opacity = std::round(255.0f * (animationDuration - (elapsedTime > animationDuration ? animationDuration : elapsedTime)));
		}

		Color color = {255, 255, 255, opacity};
		BeginDrawing();
		ClearBackground(bgColor);
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, 220}, 90, 5, {255, 255, 255, 255});
		DrawTextEx(font, "Estudio CEIVE", {(480 - sizeB.x) / 2, 600}, 35, 5, color);
		DrawTextEx(font, "by Rebun", {(480 - sizeC.x) / 2, 645}, 20, 5, color);
		EndDrawing();
	}
	animationDuration = 1.f;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime())
	{
		BeginDrawing();
		ClearBackground(bgColor);
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, (220 - elapsedTime * 120 / animationDuration)}, 90, 5, {255, 255, 255, 255});
		EndDrawing();
	}
	animationDuration = 0.15f;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime()) {
		BeginDrawing();
		ClearBackground(elapsedTime > .05f && elapsedTime < .1f ? bgColor : WHITE);
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, 100}, 90, 5, {255, 255, 255, 255});
		EndDrawing();
	}
}