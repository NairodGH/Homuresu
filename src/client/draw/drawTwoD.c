#include "includes.h"

void drawSpriteTwoD(game_t *game)
{
    node_t *node = NULL;
    sprite_t *temp = NULL;

    foreach(game->sprite->head, node) {
        temp = (sprite_t *)node->data;
        DrawTextureEx(temp->texture, temp->position, 0, temp->scale, temp->tint);
    }
}