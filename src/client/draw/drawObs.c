#include "includes.h"

void drawObs(Camera *camera, cube_t cube[MAX_COLUMNS], bullet_t *head, sprite_t *sprite)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(*camera);
    DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY);
    for (int i = 0; i < MAX_COLUMNS; i++)
        DrawCube(cube[i].position, cube[i].width, cube[i].height, cube[i].length, cube[i].color);
    drawBullet(head);
    EndMode3D();
    DrawTexture(sprite[0].texture, sprite[0].position.x, sprite[0].position.y, WHITE);
    DrawText("First person camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
    EndDrawing();
}
