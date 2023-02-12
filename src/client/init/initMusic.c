#include "includes.h"

void initMusic(game_t *game)
{
    // game->music = calloc(1, sizeof(Music));
    game->music = LoadMusicStream("assets/sounds/music.wav");
    SetMusicVolume(game->music, 0.2);
    PlayMusicStream(game->music);
}
