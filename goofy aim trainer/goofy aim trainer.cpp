#include <raylib.h>
#include <raymath.h>
#include "Button.h"
#include "gridshot.h"
int main(void)
{
    InitWindow(0, 0, "goofy aim trainer");
    settings scurrent;
    ToggleFullscreen();
    SetTargetFPS(60);
    scurrent.screenHeight = GetScreenHeight();
    scurrent.screenWidth = GetScreenWidth();
    scurrent.FPS = GetMonitorRefreshRate(GetCurrentMonitor());
    gridshot gs(scurrent);
    gs.start(scurrent);

    return 0;
}
