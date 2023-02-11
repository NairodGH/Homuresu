#include "includes.h"

void drawBullet(game_t *game)
{
    node_t *node = NULL;
    bullet_t *temp = NULL;

    foreach(game->bullet->head, node) {
        temp = (bullet_t *)node->data;
        DrawSphere(temp->position, temp->size, temp->colors);
        temp->position = Vector3Add(temp->position, Vector3Scale(temp->direction, temp->speed));
    }
}
