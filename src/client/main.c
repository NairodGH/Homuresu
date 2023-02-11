#include "includes.h"

int main(void)
{
    game_t *game = calloc(1, sizeof(game_t));

    initGame(game);
    mainLoop(game);

    free(game);
    return 0;
}
