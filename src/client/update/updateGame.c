#include "includes.h"

void updateGame(game_t *game)
{
    game->cameraLastPosition = game->camera.position;
    UpdateCamera(&game->camera);
    updateCollision(game);
    updateEvent(game);
    updateDeadBullet(game);
    updateDeadItem(game);
    // checkCube(game);
    // checkWall(game);
    // checkBullet(game);
}
