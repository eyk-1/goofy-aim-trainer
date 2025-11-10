#include "task.h"
#include <raylib.h>
task::task(settings &s) {
	screenWidth = s.screenWidth;
	screenHeight = s.screenHeight;
	FPS = s.FPS;
	target = s.target;
	radius = 45.0f;
	pause = 0;
}
