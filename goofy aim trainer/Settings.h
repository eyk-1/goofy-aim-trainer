#pragma once
#include <raylib.h>
#include "Button.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "raygui.h"


struct settings {
	int screenWidth;
	int screenHeight;
	int FPS;
	Color top = { 3, 0, 20, 255 };
	Color bottom = { 21, 0, 58, 255 };
	Color target = ColorLerp(top, bottom, 0.5f);
	Button pause;
	Button resume;
	Button settingsb;
	Button leavegame;
	settings()
		: screenWidth(1920),
		screenHeight(1080),
		FPS(60),
		top{ 3, 0, 20, 255 },
		bottom{ 21, 0, 58, 255 },
		target(ColorLerp(top, bottom, 0.5f)),
		pause("Resources/pause.png", { float(screenWidth - 50),10 }, 0.1f),
		resume("Resources/resume.png", { 100,100 }, 1.0f),
		settingsb("Resources/settings.png", { 100,300 },1.0f),
		leavegame("Resources/leavegame.png", { 100,500 },1.0f)
	{}
    void settingsPressed() {
        int FPSoptions[] = { 60, 120, 144, 165, 240, 0 };
        std::pair<int, int> resOptions[7] = {
            { GetMonitorWidth(0), GetMonitorHeight(0) },
            { 1920, 1080 },
            { 1680, 1050 },
            { 1366, 768 },
            { 1440, 900 },
            { 1280, 800 },
            { 1024, 768 }
        };
        int currFPSindex = 0;
        int currResindex = 0;

        while (!WindowShouldClose()) {
            SetExitKey(KEY_ESCAPE);
            resume.Hover();
            settingsb.Hover();
            leavegame.Hover();
            if (resume.isPressed()) return;

            if (settingsb.isPressed()) {
                while (!WindowShouldClose()) {
                    if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_ESCAPE)) break;

                    BeginDrawing();
                    ClearBackground(LIGHTGRAY);

                    // --- Title ---
                    const char* title = "SETTINGS";
                    DrawText(title, (screenWidth - MeasureText(title, 50)) / 2, 30, 50, DARKGRAY);

                    // --- FPS --- 
                    DrawText("FPS", screenWidth * 0.05, screenHeight * 0.125, 30, BLACK);
                    GuiToggleGroup(
                        { screenWidth * 0.2f, screenHeight * 0.125f, (screenWidth * 0.75f) / 6, 40 },
                        "60;120;144;165;240;Unlimited",
                        &currFPSindex
                    );
                    if (FPSoptions[currFPSindex] != FPS) {
                        FPS = FPSoptions[currFPSindex];
                        SetTargetFPS(FPS);
                    }

                    // --- Resolution --- 
                    DrawText("Resolution", screenWidth * 0.05, screenHeight * 0.25, 30, BLACK);
                    GuiToggleGroup(
                        { screenWidth * 0.2f, screenHeight * 0.25f, (screenWidth * 0.75f) / 7, 40 },
                        "Native;1920x1080;1680x1050;1366x768;1440x900;1280x800;1024x768",
                        &currResindex
                    );
                    if (screenWidth != resOptions[currResindex].first ||
                        screenHeight != resOptions[currResindex].second) {
                        screenWidth = resOptions[currResindex].first;
                        screenHeight = resOptions[currResindex].second;
                        SetWindowSize(screenWidth, screenHeight);
                    }

                    // --- Back instruction ---
                    const char* backText = "Press ESC or BACKSPACE to go back";
                    DrawText(backText, (screenWidth - MeasureText(backText, 20)) / 2, screenHeight - 50, 20, DARKGRAY);
                    EndDrawing();
                }
            }

            BeginDrawing();
            ClearBackground(RAYWHITE);
            resume.Draw();
            settingsb.Draw();
            leavegame.Draw();
            EndDrawing();
        }
    }
    

};