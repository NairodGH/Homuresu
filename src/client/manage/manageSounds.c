#include "includes.h"

Music *getSound(game_t *game, sound_e type)
{
    node_t *node = NULL;
    sound_t *sound = NULL;

    foreach(game->sound->head, node) {
        sound = (sound_t *)node->data;
        if (sound->type == type) {
            return &(sound->sound);
        }
    }
    return NULL;
}

void playSound(game_t *game, sound_e type)
{
    Music *sound = getSound(game, type);

    if (sound != NULL) {
        // PlaySound(*sound);
        PlayMusicStream(*sound);
        // TODO
    }
}

void playSoundMulti(game_t *game, sound_e type)
{
    Music *sound = getSound(game, type);

    if (sound != NULL) {
        // PlaySoundMulti(*sound);
        PlayMusicStream(*sound);
        // TODO
    }
}
