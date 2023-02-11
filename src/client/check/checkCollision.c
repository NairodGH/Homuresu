#include "includes.h"

void checkCollision(Camera *camera, Vector3 cameraLastPosition, cube_t cube[MAX_COLUMNS])
{
    for (int i = 0; i < MAX_COLUMNS; i++) {
        if (CheckCollisionRecs((Rectangle){camera->position.x, camera->position.z, 1, 1},
            (Rectangle){cube[i].position.x, cube[i].position.z, 1, 1}))
            camera->position = cameraLastPosition;
    }
}
