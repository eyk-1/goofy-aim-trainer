#pragma once
#include <raylib.h>
#include "Button.h"
struct settings {
	int screenWidth;
	int screenHeight;
	int FPS;
	Vector2 pausepos = { float(screenWidth - 50),10 };
	Color top = { 3, 0, 20, 255 };
	Color bottom = { 21, 0, 58, 255 };
	Color target = ColorLerp(top, bottom, 0.5f);
	Button settingsbutton;	
	settings()
		: screenWidth(1920), // or defaults until you set them later
		screenHeight(1080),
		FPS(60),
		top{ 3, 0, 20, 255 },
		bottom{ 21, 0, 58, 255 },
		target(ColorLerp(top, bottom, 0.5f)),
		pausepos{ float(screenWidth - 50), 10 },
		settingsbutton("Resources/pause.png", pausepos, 0.1f)
	{}
	void settingsPressed() {
		while (!WindowShouldClose()) {
			SetExitKey(KEY_ESCAPE);
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Bogus binted", 100, 100, 10, BLACK);
			EndDrawing();
		}
	}
};