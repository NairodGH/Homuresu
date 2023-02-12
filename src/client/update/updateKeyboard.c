#include "includes.h"

void sprint(game_t *game, bool isPressed)
{
    game->speed = isPressed;
}

void jump(game_t *game, bool isPressed)
{
    if (isPressed && game->height == 1.0f)
        game->height -= 0.1f;
}

void walk(game_t *game, bool isPressed)
{
    Sound *sound = getSound(game, SOUND_WALK);
    if (sound && IsSoundPlaying(*sound))
        return;
    playSound(game, SOUND_WALK);
}