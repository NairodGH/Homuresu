#include "includes.h"

static void updateMusic(game_t *game)
{
    if (IsSoundPlaying(game->music))
        return;
    PlaySound(game->music);
}

void updateGame(game_t *game)
{
    game->cameraLastPosition = game->camera.position;
    updateMusic(game);
    UpdateCamera(&(game->camera));
    updateCollision(game);
    updateEvent(game);
    updateDeadBullet(game);
    updateDeadItem(game);
}
