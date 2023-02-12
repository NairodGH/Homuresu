#include "includes.h"

void drawGame(game_t *game)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // 3D
    BeginMode3D(game->camera);
    drawCube(game);
    drawBullet(game);
    drawItem(game);
    // add ...

    EndMode3D();
    drawSpriteTwoD(game);
    // 2D
    // add ...

    EndDrawing();
}
