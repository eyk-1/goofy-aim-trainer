#include <raylib.h>
#include <raymath.h>

int main(void)
{
    //int screenWidth = GetMonitorWidth(0);
    //int screenHeight = GetMonitorHei  ght(0);
    int screenWidth = 1280;
    int screenHeight = 720;
    float gridWidth = (float)screenWidth / 4;
    float gridHeight = (float)screenHeight / 4;
    int index = 0;
    InitWindow(screenWidth, screenHeight, "dung beetles is a funny word");
    SetTargetFPS(60);
    Color top = { 3, 0, 20, 255 };
    Color bottom = { 21, 0, 58, 255 };
    Color swag = ColorLerp(top, bottom, 0.5f);
    float radius = 45.0f;
    Vector2 ballPosition[9];
    for (int i = 1; i < 4; i++) { // pre-compute positions for the grid.
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

    while (!WindowShouldClose())
    {
        Vector2 CurrentMousePosition = GetMousePosition();
        for (int i = 0; i < 3; i++) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
                Vector2Distance(CurrentMousePosition, ballPosition[pos[i]])
                <= radius) {
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
        }
        if (missed + score > 0) accuracy = ((float)score / (float)(score + missed)) * 100;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("goofy aim trainer", 10, 10, 20, BLACK);
        DrawFPS(screenWidth - 90, 10);
        DrawText(TextFormat("Current resolution: %dx%d", screenWidth, screenHeight), 10, 50, 20, BLACK);
        DrawText(TextFormat("Score: %d ", score), 10, 80, 30, RED);
        DrawText(TextFormat("Accuracy: %.2f%%", accuracy), 10, 120, 30, RED);
        for (int i = 0; i < 3; i++) {
            DrawCircleV(ballPosition[pos[i]], radius, swag);
        }
        EndDrawing();

    }
    UnloadRandomSequence(pos);
    CloseWindow();

    return 0;
}
