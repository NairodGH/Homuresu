#include "includes.h"

void createBullet(game_t *game, float speed, float size)
{
    bullet_t *new = calloc(1, sizeof(bullet_t));

    new->position = (Vector3){game->camera.position.x, game->camera.position.y, game->camera.position.z};
    new->target = (Vector3){game->camera.target.x, game->camera.target.y, game->camera.target.z};
    new->direction = Vector3Normalize(Vector3Subtract(new->target, new->position));
    new->speed = speed;
    new->size = size;
    new->colors = RED;
    new->isAlive = true;
    list_push_data(game->bullet, new);
}
