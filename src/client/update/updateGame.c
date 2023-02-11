#include "includes.h"

void updateGame(game_t *game)
{
    updateCollision(game);
    updateEvent(game);
    updateDeadBullet(game);
    // checkCube(game);
    // checkWall(game);
    // checkBullet(game);
}
