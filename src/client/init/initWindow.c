#include "includes.h"

void initWindow(const int screenWidth, const int screenHeight)
{
    SetTraceLogLevel(LOG_NONE);
    ToggleFullscreen();
    InitWindow(screenWidth, screenHeight, "Homuresu");
}
