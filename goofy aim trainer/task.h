#pragma once
#include "Settings.h"
class task
{
protected:
	float radius;
	Color target;
public:
	task(settings &s);
	virtual ~task() {}
	virtual void start(settings &s) = 0;
};

