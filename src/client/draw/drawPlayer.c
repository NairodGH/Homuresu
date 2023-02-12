#include "includes.h"

void drawPlayer(game_t *game)
{
    node_t *node = NULL;
    player_t *temp = NULL;

    foreach(game->player->head, node) {
        temp = (player_t *)node->data;
        DrawModel(temp->model.model, temp->position, 1, WHITE);
    }
}