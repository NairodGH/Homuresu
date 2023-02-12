#include "includes.h"

void initGame(game_t *game)
{
    initWindow(game->windowSize.x, game->windowSize.y);
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initCamera(game);
    initCube(game);
    initWall(game);
    initItem(game);
    initBullet(game);
    initSounds(game);
    initModels(game);
    initSprite(game);
    initStat(game);
    initMenu(game);
}
