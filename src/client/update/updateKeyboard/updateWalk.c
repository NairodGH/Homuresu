#include "includes.h"

void updateWalk(game_t *game)
{
    Sound *sound = getSound(game, SOUND_WALK);

    if (sound && IsSoundPlaying(*sound))
        return;
    playSound(game, SOUND_WALK);
}
