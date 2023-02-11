#include "includes.h"

void mainLoop(void)
{
    bullet_t *head = NULL;
    Camera camera = { 0 };

    initCamera(&camera);
    Vector3 cameraLastPosition = camera.position;
    cube_t cube[MAX_COLUMNS] = { 0 };
    sprite_t sprite[20] = { 0 };
    int i = 0;

    sprite[0] = (sprite_t){LoadTexture("assets/sprites/crosshair.png"), (Vector2){1440/2, 720/2}, (Vector2){0.5, 0.5}, 1.0f, WHITE};
    for (i = 0; i < MAX_COLUMNS - 4; i++) {
        cube[i].width = 2.0f;
        cube[i].length = 2.0f;
        cube[i].height = (float)GetRandomValue(1, 12);
        cube[i].position = (Vector3){ (float)GetRandomValue(-15, 15), cube[i].height/2.0f, (float)GetRandomValue(-15, 15) };
        cube[i].color = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }
    initWall(i, cube);
    while (!WindowShouldClose()) {
        cameraLastPosition = camera.position;
        UpdateCamera(&camera);
        checkCollision(&camera, cameraLastPosition, cube);
        drawObs(&camera, cube, head, sprite);
        if (IsKeyPressed(KEY_ENTER)) {
            if (head == NULL)
                head = initListBullet(0.2, 0.05, &camera);
            else
                createBullet(head, 0.2, 0.05, &camera);
        }
    }
    CloseWindow();
}
