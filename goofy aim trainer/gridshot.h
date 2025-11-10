#pragma once
#include <raylib.h>
#include "task.h"
class gridshot :
    public task
{
public:
    gridshot(settings &s);
    ~gridshot();
    void start(settings& s);
};

