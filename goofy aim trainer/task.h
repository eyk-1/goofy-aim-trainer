#pragma once
#include "Settings.h"
class task
{
protected:
	int screenWidth;
	int screenHeight;
	int FPS;
	float radius;
	Color target;
	bool pause;
public:
	task(settings &s);
	virtual ~task() {}
	virtual void start(settings &s) = 0;
};

