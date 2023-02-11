#include "includes.h"

void initGame(game_t *game)
{
    initWindow(game->windowSize.x, game->windowSize.y);
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initCamera(game);
    initCube(game);
    initWall(game);
    initBullet(game);
    initMenu(game);
}
