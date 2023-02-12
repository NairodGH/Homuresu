#include "includes.h"

void updateEnter(game_t *game)
{
    createBullet(game, 0.06, 0.05);

    Sound *sound = getSound(game, SOUND_SHOT);

    if (sound && IsSoundPlaying(*sound))
        return;
    playSound(game, SOUND_SHOT);
}
