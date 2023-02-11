#include "includes.h"

void initWindow(const int screenWidth, const int screenHeight)
{
    SetTraceLogLevel(LOG_NONE);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");
}
