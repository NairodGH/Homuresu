#include "includes.h"

void initGame(game_t *game)
{
    initWindow(1440, 720);
    initCamera(&game->camera);
    initCube(game);
    initWall(game);
    initBullet(game);
}
