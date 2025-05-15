#include <memory>
#include <vector>
#include "core/gameState/menuState.h"
#include "raylib.h"
#include "core/gameInterface.h"
#include "config.h"
// #include "network.h"

#include "resource_dir.h" // utility header for SearchAndSetResourceDir
#include "style/colors.h"

void loadingScreen();

int main()
{
	// Tell the window to use vsync and work on high DPI displays
	// SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(TARGET_FPS);
	SetTraceLogLevel(LOG_DEBUG);

	// Register UDP Driver for NBnet
	// NBN_UDP_Register();

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	
	std::shared_ptr<GameInterface> game = GameInterface::getGameInstance();
	MenuState state = MenuState();
	game->setState(state);

	loadingScreen();

	// game loop
	while (!(WindowShouldClose() || game->gameShouldClose())) // run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		game->handleInput();

		// Update
		game->update();

		// drawing
		BeginDrawing();
		ClearBackground(GetThemeColor(BG_COLOR));
		// Draw game
		game->draw();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	};

	// cleanup
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}

void loadingScreen()
{
	unsigned char opacity = 0;
	Font font = GameInterface::getGameInstance()->getFont();
	Vector2 sizeA = MeasureTextEx(font, "PARCHIS", 90, 5);
	Vector2 sizeB = MeasureTextEx(font, "Estudio CEIVE", 35, 5);
	Vector2 sizeC = MeasureTextEx(font, "by Rebun", 20, 5);

	Shader shader = LoadShader(0, TextFormat("shaders/glsl%i/bloom.fs", GLSL_VERSION));

	float animationDuration = 3.0f;
	std::vector<float> animation = {1.5f, 1.6f, 1.7f, 2.8f, 100.0f};
	int animationCounter = 0;
	bool shaderActive = false;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime())
	{
		if (elapsedTime > animation[animationCounter])
		{
			shaderActive = !shaderActive;
			animationCounter++;
		}
		BeginDrawing();
		if (shaderActive)
		{
			BeginShaderMode(shader);
		}
		ClearBackground(GetThemeColor(BG_COLOR));
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, 220}, 90, 5, WHITE);
		DrawTextEx(font, "Estudio CEIVE", {(480 - sizeB.x) / 2, 600}, 35, 5, WHITE);
		DrawTextEx(font, "by Rebun", {(480 - sizeC.x) / 2, 645}, 20, 5, WHITE);
		if (shaderActive)
		{
			EndShaderMode();
		}
		EndDrawing();
	}
	animationDuration = 1.f;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime())
	{
		BeginDrawing();
		ClearBackground(GetThemeColor(BG_COLOR));
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, (220 - elapsedTime * 120 / animationDuration)}, 90, 5, {255, 255, 255, 255});
		EndDrawing();
	}
	animationDuration = 0.15f;
	for (float elapsedTime = 0.f; elapsedTime < animationDuration; elapsedTime += GetFrameTime())
	{
		BeginDrawing();
		ClearBackground(elapsedTime > .05f && elapsedTime < .1f ? GetThemeColor(BG_COLOR) : WHITE);
		DrawTextEx(font, "PARCHIS", {(480 - sizeA.x) / 2, 100}, 90, 5, {255, 255, 255, 255});
		EndDrawing();
	}
	UnloadShader(shader);
}