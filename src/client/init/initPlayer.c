#include "includes.h"

void initPlayer(game_t *game)
{
    game->player = calloc(1, sizeof(player_t));
}
