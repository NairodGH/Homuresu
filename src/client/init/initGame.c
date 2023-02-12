#include "includes.h"

void initGame(game_t *game)
{
    game->windowSize = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    initWindow(game->windowSize.x, game->windowSize.y);
    game->id = -1;
    initCamera(game);
    initModels(game);
    initItem(game);
    initBullet(game);
    initCube(game);
    initWall(game);
    initMusic(game);
    initSounds(game);
    initSprite(game);
    initStat(game);
    initPlayer(game);
    initMenu(game);
}
