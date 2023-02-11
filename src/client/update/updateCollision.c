#include "includes.h"

static void checkCollisionBullet(game_t *game, cube_t *cube)
{
    node_t *node = NULL;
    bullet_t *temp = NULL;

    foreach(game->bullet->head, node) {
        temp = (bullet_t *)node->data;
        if (temp->isAlive == false)
            continue;
        if (temp->position.x > cube->position.x - cube->width / 2 &&
            temp->position.x < cube->position.x + cube->width / 2 &&
            temp->position.z > cube->position.z - cube->length / 2 &&
            temp->position.z < cube->position.z + cube->length / 2) {
            temp->isAlive = false;
        }
    }
}

void checkCollision(game_t *game)
{
    node_t *node = NULL;
    cube_t *temp = NULL;

    foreach(game->cube->head, node) {
        temp = (cube_t *)node->data;
        // if (game->camera.position.x > temp->position.x - temp->width / 2 &&
        //     game->camera.position.x < temp->position.x + temp->width / 2 &&
        //     game->camera.position.z > temp->position.z - temp->length / 2 &&
        //     game->camera.position.z < temp->position.z + temp->length / 2)
        //     game->camera.position = game->cameraLastPosition;
        checkCollisionBullet(game, temp);
    }
}

void updateCollision(game_t *game)
{
    checkCollision(game);
}
