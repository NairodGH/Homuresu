#include "includes.h"

void createProjectile(game_t *game, float speed, float size)
{
    projectile_t *new = calloc(1, sizeof(projectile_t));

    new->position = game->camera.position;
    new->direction = Vector3Normalize(Vector3Subtract((Vector3){game->camera.target.x, game->camera.target.y, game->camera.target.z}, new->position));
    new->speed = speed;
    new->size = size;
    new->model = LoadModel("resources/batarang/Batarang.obj");

    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    list_push_data(game->projectile, new);
}
