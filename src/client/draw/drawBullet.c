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

void drawItem(game_t *game)
{
    node_t *node = NULL;
    item_t *temp = NULL;

    foreach(game->item->head, node) {
        temp = (item_t *)node->data;
        Vector3 pos = temp->position;
        temp->model.transform = MatrixRotateX(270.0f * DEG2RAD);
        temp->model.transform = MatrixMultiply(temp->model.transform, MatrixScale(0.03, 0.1, 0.03));
        DrawModel(temp->model, temp->position, 1, WHITE);
    }
}
