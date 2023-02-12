#include "includes.h"

void shoot(game_t *game, bool isPressed)
{
    if (isPressed)
        createProjectile(game, 0.1, 0.1);
}
