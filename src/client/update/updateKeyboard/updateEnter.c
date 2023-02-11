#include "includes.h"

void updateEnter(game_t *game)
{
    if (game->stat->ammo <= 0 || game->stat->lastShoot != 0
        && time(NULL) - game->stat->lastShoot < game->stat->cooldownShoot)
        return;
    createBullet(game, 0.3, 0.05);
}
