#include "includes.h"

void initGame(game_t *game)
{
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initWindow(game->windowSize.x, game->windowSize.y);
    initCamera(game);
    initCube(game);
    initWall(game);
    initItem(game);
    initBullet(game);
    initMusic(game);
    initSounds(game);
    initModels(game);
    initSprite(game);
    initStat(game);
    initMenu(game);
}
