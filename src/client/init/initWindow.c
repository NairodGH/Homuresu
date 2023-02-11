#include "includes.h"

void initWindow(const int screenWidth, const int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Monke");
    ToggleFullscreen();
    SetTraceLogLevel(LOG_NONE);
}
