#include "includes.h"

void drawCube(game_t *game)
{
    node_t *node = NULL;
    cube_t *temp = NULL;

    foreach(game->cube->head, node) {
        temp = (cube_t *)node->data;
        DrawCubeV(temp->position, (Vector3){temp->width, temp->height, temp->length}, temp->color);
    }
    DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
}
