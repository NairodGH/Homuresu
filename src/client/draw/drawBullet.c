#include "includes.h"

void drawBullet(game_t *game)
{
    node_t *node = NULL;
    bullet_t *temp = NULL;

    foreach(game->bullet->head, node) {
        temp = (bullet_t *)node->data;
        DrawModel(temp->model, temp->position, 1, WHITE);
        temp->position = Vector3Add(temp->position, Vector3Scale(temp->direction, temp->speed));
    }
}
