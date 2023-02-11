#include "includes.h"

void initCamera(Camera *camera)
{
    camera->position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera->target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera->fovy = 60.0f;
    camera->projection = CAMERA_PERSPECTIVE;
    SetCameraAltControl(KEY_LEFT_ALT);
    SetCameraMode(*camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);
}
