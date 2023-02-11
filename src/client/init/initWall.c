#include "includes.h"

void initWall(int i, cube_t cube[MAX_COLUMNS])
{
    cube[i] = (cube_t){(Vector3){ 0.0f, 0.0f, -16.0f }, 32.0f, 16.0f, 0.1f, GRAY};
    cube[i + 1] = (cube_t){(Vector3){ 0.0f, 0.0f, 16.0f }, 32.0f, 16.0f, 0.1f, GRAY};
    cube[i + 2] = (cube_t){(Vector3){ 16.0f, 0.0f, 0.0f }, 0.1f, 16.0f, 32.0f, GRAY};
    cube[i + 3] = (cube_t){(Vector3){ -16.0f, 0.0f, 0.0f }, 0.1f, 16.0f, 32.0f, GRAY};
}
