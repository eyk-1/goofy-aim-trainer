#include "task.h"
#include <raylib.h>
task::task(settings &s) {
	target = s.target;
	radius = 45.0f;
}
