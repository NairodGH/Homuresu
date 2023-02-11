#include "includes.h"

void initCamera(game_t *game)
{
    game->camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    game->camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    game->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->camera.fovy = 60.0f;
    game->camera.projection = CAMERA_PERSPECTIVE;
    SetCameraAltControl(KEY_LEFT_ALT);
    SetCameraMode(game->camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);
    game->cameraLastPosition = game->camera.position;
}
