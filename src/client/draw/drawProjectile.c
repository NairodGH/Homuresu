#include "includes.h"

void drawProjectile(game_t *game)
{
    node_t *node = NULL;
    projectile_t *temp = NULL;

    foreach(game->projectile->head, node) {
        temp = (projectile_t *)node->data;
        DrawModel(temp->model, temp->position, 1, WHITE);
        temp->position = Vector3Add(temp->position, Vector3Scale(temp->direction, temp->speed));
    }
}
