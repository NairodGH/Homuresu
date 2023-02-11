#include "includes.h"

void createBullet(game_t *game, float speed, float size)
{
    bullet_t *new = calloc(1, sizeof(bullet_t));

    new->position = (Vector3){game->camera.position.x, game->camera.position.y, game->camera.position.z};
    new->direction = Vector3Normalize(Vector3Subtract((Vector3){game->camera.target.x, game->camera.target.y, game->camera.target.z}, new->position));
    new->speed = speed;
    new->size = size;
    new->model = *getModel(game, MODEL_DORION2);
    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    list_push_data(game->bullet, new);
    game->stat->lastShoot = time(NULL);
    game->stat->ammo--;
}

void createAmmoBox(game_t *game)
{
    item_t *new = calloc(1, sizeof(item_t));

    new->position = (Vector3){GetRandomValue(-(MAP_SIZE / 2) + 1, (MAP_SIZE / 2) - 1),
                              0, GetRandomValue(-(MAP_SIZE / 2) + 1, (MAP_SIZE / 2) - 1)};
    new->texture = LoadTexture("resources/ammoBox.png");
    new->height = 1.0f;
    new->width = 1.0f;
    new->length = 1.0f;
    new->name = "ammoBox";
    new->isAlive = true;
    list_push_data(game->item, new);
}
