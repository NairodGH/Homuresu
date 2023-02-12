#include "includes.h"

static void updateMusic(game_t *game)
{
    if (IsSoundPlaying(game->music))
        return;
    PlaySound(game->music);
}

void updateGame(game_t *game)
{
    updateMusic(game);
    game->cameraLastPosition = game->camera.position;
    UpdateCamera(&game->camera);
    if (game->height != 1.0f) {
        game->camera.position.y += game->height;
        game->height += (game->gravity -= 0.1f);
        if (game->gravity < -1.0f)
            game->height = game->gravity = 1.0f;
    }
    game->camera.position.x += (game->camera.position.x - game->cameraLastPosition.x) * game->speed * 1.5;
    game->camera.position.z += (game->camera.position.z - game->cameraLastPosition.z) * game->speed * 1.5;
    updateCollision(game);
    updateEvent(game);
    updateDeadProjectile(game);
}
