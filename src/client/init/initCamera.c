#include "includes.h"

void initCamera(game_t *game)
{
    game->cameraLastPosition = game->camera.position = (Vector3){ 0.0f, 10.0f, 0.0f };
    game->cameraLastTarget = game->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    game->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->camera.fovy = 45.0f;
    game->camera.projection = CAMERA_PERSPECTIVE;
    game->height = game->gravity = 1.0f;
    game->speed = 0.0f;
    SetCameraAltControl(KEY_LEFT_ALT);
    SetCameraMode(game->camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);
}
