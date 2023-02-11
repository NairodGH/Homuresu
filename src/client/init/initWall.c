#include "includes.h"

static cube_t *createWall(Vector3 pos, float width, float height, float length, Color color)
{
    cube_t *temp = calloc(1, sizeof(cube_t));

    temp->position = pos;
    temp->width = width;
    temp->height = height;
    temp->length = length;
    temp->color = color;
    return temp;
}

void initWall(game_t *game)
{
    list_push_data(game->cube, createWall((Vector3){ 0.0f, 0.0f, -16.0f }, 32.0f, 16.0f, 0.1f, GRAY));
    list_push_data(game->cube, createWall((Vector3){ 0.0f, 0.0f, 16.0f }, 32.0f, 16.0f, 0.1f, GRAY));
    list_push_data(game->cube, createWall((Vector3){ 16.0f, 0.0f, 0.0f }, 0.1f, 16.0f, 32.0f, GRAY));
    list_push_data(game->cube, createWall((Vector3){ -16.0f, 0.0f, 0.0f }, 0.1f, 16.0f, 32.0f, GRAY));
}

void initCube(game_t *game)
{
    cube_t *temp = NULL;

    game->cube = list_create();

    for (int i = 0; i < OBS_NBR; i++) {
        temp = calloc(1, sizeof(cube_t));
        temp->width = 2.0f;
        temp->length = 2.0f;
        temp->height = (float)GetRandomValue(8, 12);
        temp->position = (Vector3){(float)GetRandomValue(-15, 15), temp->height / 2.0f, (float)GetRandomValue(-15, 15)};
        temp->color = BLUE;
        list_push_data(game->cube, temp);
    }
}
