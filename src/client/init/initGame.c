#include "includes.h"

void initGame(game_t *game)
{
    initWindow(1280, 720);
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initCamera(game);
    initCube(game);
    initWall(game);
    initBullet(game);
    initMenu(game);
}
