
#include "includes.h"

void updateDeadBullet(game_t *game)
{
    list_node_t *node = NULL;
    list_node_t *safe = NULL;
    bullet_t *temp = NULL;

    foreach_safe(game->bullet->head, node, safe) {
        temp = (bullet_t *)node->data;
        if (temp->isAlive == false) {
            remove_node(game->bullet, node);
            destroy_node(node, free);
        }
    }
}
