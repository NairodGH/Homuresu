
#include "includes.h"

void updateDeadBullet(game_t *game)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    bullet_t *temp = NULL;

    foreach_safe(game->bullet->head, node, safe) {
        temp = (bullet_t *)node->data;
        if (temp->isAlive == false) {
            // UnloadModel(temp->model);
            list_destroy_data_node(game->bullet, node->data, free);
        }
    }
}

void updateDeadItem(game_t *game)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    item_t *temp = NULL;

    foreach_safe(game->item->head, node, safe) {
        temp = (item_t *)node->data;
        if (temp->isAlive == false) {
            // UnloadTexture(temp->texture);
            list_destroy_data_node(game->item, node->data, free);
        }
    }
}
