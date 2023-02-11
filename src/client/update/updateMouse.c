#include "includes.h"

void shoot(game_t *game, bool isPressed)
{
    if (isPressed)
        createBullet(game, 0.06, 0.05);
}
