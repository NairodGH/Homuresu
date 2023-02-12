#include "includes.h"

int main(void)
{
    game_t *game = calloc(1, sizeof(game_t));

    InitAudioDevice();
    initGame(game);
    mainLoop(game);
    return 0;
}
