#include "includes.h"

void updateGame(game_t *game)
{
    game->cameraLastPosition = game->camera.position;
    game->cameraLastTarget = game->camera.target;
    UpdateCamera(&game->camera);
    updateCollision(game);
    updateEvent(game);
    updateDeadBullet(game);
}
