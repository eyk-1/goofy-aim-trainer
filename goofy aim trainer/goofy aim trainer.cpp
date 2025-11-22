#define _CRT_SECURE_NO_WARNINGS
#include <raylib.h>
#include <raymath.h>
#include "Button.h"
#include "gridshot.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
int main(void)
{
    InitWindow(0, 0, "goofy aim trainer");
    settings scurrent;
    //SetWindowState(FLAG_WINDOW_UNDECORATED); // Removes borders
    //ToggleBorderlessWindowed();
    ToggleFullscreen();
    SetTargetFPS(60);
    scurrent.screenHeight = GetScreenHeight();
    scurrent.screenWidth = GetScreenWidth();
    scurrent.FPS = GetMonitorRefreshRate(GetCurrentMonitor());
    gridshot gs(scurrent);
    gs.start(scurrent);

    return 0;
}
