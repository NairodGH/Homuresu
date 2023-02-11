#include "includes.h"

void mainLoop(game_t *game)
{
    while (!WindowShouldClose()) {
        if (game->menu->is_menu) {
            // menu(game->menu);
        } else {
            updateGame(game);
            drawGame(game);
        }
    }
    CloseWindow();
}
