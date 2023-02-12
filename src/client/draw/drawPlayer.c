#include "includes.h"

void drawPlayer(game_t *game)
{
    node_t *node = NULL;
    player_t *temp = NULL;

    foreach(game->player->head, node) {
        temp = (player_t *)node->data;
        if (temp->isAlive) {
            temp->model.model.transform = MatrixRotateZ(270 * DEG2RAD);
            temp->model.model.transform = MatrixMultiply(
                temp->model.model.transform, MatrixScale(0.6, 0.6, 0.6));
            temp->model.model.transform = MatrixMultiply(
                temp->model.model.transform, MatrixRotateY(atan2(temp->direction.x, temp->direction.z)));
            DrawModel(temp->model.model, temp->position, 1, WHITE);
        }
    }
}