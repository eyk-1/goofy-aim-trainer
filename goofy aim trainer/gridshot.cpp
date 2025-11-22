#include "gridshot.h"
#include "raymath.h"
gridshot::gridshot(settings &s) : task(s) {}

gridshot::~gridshot()
{
    
}


void gridshot::start(settings& s) {
    s.screenWidth = GetScreenWidth();
    s.screenHeight = GetScreenHeight();
    float gridWidth = (float)(s.screenWidth / 4);
    float gridHeight = (float)(s.screenHeight / 4);
    int index = 0;
    Vector2 ballPosition[9];
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            ballPosition[index].x = i * gridWidth;
            ballPosition[index].y = j * gridHeight;
            index++;
        }
    }
    int* pos = LoadRandomSequence(3, 0, 8);

    int score = 0;
    int missed = 0;
    float accuracy = 100.0f;
    int totalshots = 0.0f;
    while (!WindowShouldClose())
    {
        SetExitKey(KEY_NULL);
        Vector2 CurrentMousePosition = GetMousePosition();
        if (s.pause.isPressed() || IsKeyPressed(KEY_ESCAPE)) {
            s.settingsPressed();
            // applying the settings and updating the positions
            s.screenWidth = GetScreenWidth();
            s.screenHeight = GetScreenHeight();
            gridWidth = (float)(s.screenWidth / 4);
            gridHeight = (float)(s.screenHeight / 4);
            index = 0;
            for (int i = 1; i < 4; i++) {
                for (int j = 1; j < 4; j++) {
                    ballPosition[index].x = i * gridWidth;
                    ballPosition[index].y = j * gridHeight;
                    index++;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                CheckCollisionPointCircle(CurrentMousePosition, ballPosition[pos[i]], radius)) {
                score++;
                int newIndex = GetRandomValue(0, 8);
                bool dupe = true;
                while (dupe) {
                    dupe = 0;
                    for (int j = 0; j < 3; j++) {
                        if (newIndex == pos[j]) {
                            dupe = true;
                            newIndex = GetRandomValue(0, 8);
                            break;
                        }
                    }
                }
                pos[i] = newIndex;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                Vector2Distance(CurrentMousePosition, ballPosition[pos[i]])
                >= radius) {
                missed++;
            }
            totalshots = missed + score;
        }
        if (totalshots > 0) accuracy = ((float)score/3 / (float)(totalshots/3)) * 100;
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("goofy aim trainer", 10, 10, 20, BLACK);
        DrawFPS(s.screenWidth - 300, 20);
        DrawText(TextFormat("Current resolution: %dx%d", s.screenWidth, s.screenHeight), 10, 30, 20, BLACK);
        DrawText(TextFormat("Score: %d ", score), 10, 50, 30, RED);
        DrawText(TextFormat("Accuracy: %.2f%%", accuracy), 10, 100, 30, RED);
        DrawText(TextFormat("Shots: %d ", totalshots/3), 10, 150, 30, RED);
        s.pause.Draw();
        for (int i = 0; i < 3; i++) {
            DrawCircleV(ballPosition[pos[i]], radius, target);
        }
        EndDrawing();

    }
    UnloadRandomSequence(pos);
    CloseWindow();
}
