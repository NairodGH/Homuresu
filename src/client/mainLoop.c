#include "includes.h"

void mainLoop(game_t *game)
{
    while (!WindowShouldClose()) {
        updateGame(game);
        drawGame(game);
    }
    CloseWindow();
}
