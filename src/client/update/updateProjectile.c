
#include "includes.h"

void updateDeadProjectile(game_t *game)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    projectile_t *temp = NULL;

    foreach_safe(game->projectile->head, node, safe) {
        temp = (projectile_t *)node->data;
        if (temp->isAlive == false) {
            // UnloadModel(temp->model);
            list_destroy_data_node(game->projectile, node, free);
        }
    }
}
