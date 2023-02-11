#include "includes.h"

void sprint(game_t *game)
{
}

void jump(game_t *game)
{
    for (size_t i = 0; i < 1000000; i++)
        game->camera.position.y += 0.01f;
}