#include <memory>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"
#include "./menus/Menu.h"
#include "./menus/MainMenu.h"
#include "./core/colors.h"
#include "./core/game.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	// SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(480, 720, "Parchix");
	SetTargetFPS(60);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	Font font = LoadFontEx("fonts/AfterARain.otf", 64, 0, 0);

	Game game = Game();

	std::stack<std::unique_ptr<Menu>> menus;
	menus.push(std::unique_ptr<Menu>(new MainMenu()));

	// game loop
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// Handle input
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			// Vector2 touchPoint = GetTouchPosition(0);
			Vector2 touchPoint = GetMousePosition();
			if (!menus.empty())
			{
				menus.top()->onTouch(touchPoint);
			}
		}

		// Update
		if (!menus.empty() && menus.top()->menuMustClose())
		{
			menus.pop();
			std::cout << "Closed menu" << std::endl;
		}

		// drawing
		BeginDrawing();
		ClearBackground(bgColor);
		// debug
		if(menus.empty()) {
			DrawText("No menu", 0, 0, 20, WHITE);
		} else {
			DrawText(menus.top()->menuMustClose() ? "Closing" : "Menu should be here", 0, 0, 20, WHITE);
		}
		// Draw game
		game.draw();
		// Draw top menu
		if (!menus.empty())
		{
			menus.top()->draw();
		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	};

	// cleanup
	UnloadFont(font);
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
