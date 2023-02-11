#include "includes.h"

void drawGame(game_t *game)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // 3D
    BeginMode3D(game->camera);
    drawCube(game);
    drawBullet(game);
    // add ...

    EndMode3D();

    // 2D
    // add ...

    EndDrawing();
}
