#include <memory>
#include <stack>
#include <string>
#include "raylib.h"
#include "./menus/Menu.h"
#include "./menus/MainMenu.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(480, 720, "Parchix");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	std::stack<std::unique_ptr<Menu>> menus;
	menus.push(std::unique_ptr<Menu>(new MainMenu()));

	// game loop
	while (!WindowShouldClose()) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// Handle input
		Vector2 touchPoint = GetTouchPosition(0);
		// Update
		if (!menus.empty())
		{
			DrawText(("Touch Point: " + std::to_string(touchPoint.x) + ", " + std::to_string(touchPoint.y)).c_str(), 0, 20, 20, WHITE);
			menus.top()->onTouch(touchPoint);
		}

		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		if (!menus.empty())
		{
			menus.top()->draw();
		}

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	};

	// cleanup

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
