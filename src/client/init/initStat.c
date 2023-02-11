#include "includes.h"

void initStat(game_t *game)
{
    game->stat = calloc(1, sizeof(stat_t));
    game->stat->ammo = 5;
    game->stat->life = 100;
    game->stat->score = 0;
    game->stat->cooldownShoot = 2.0f;
    game->stat->lastShoot = 0;
}