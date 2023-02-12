#include "includes.h"

void updateEnter(game_t *game)
{
    if (game->stat->ammo <= 0 || game->stat->lastShoot != 0
        && time(NULL) - game->stat->lastShoot < game->stat->cooldownShoot)
        return;

    Sound *sound = getSound(game, SOUND_SHOT);

    if (sound && !IsSoundPlaying(*sound)) {
        playSound(game, SOUND_SHOT);
    }
    createBullet(game, 0.3, 0.05);
}
