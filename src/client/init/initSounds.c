#include "includes.h"

typedef struct {
    sound_e type;
    const char *path;
} relation_t;

static const relation_t relation[] = {
    {SOUND_WALK, "assets/sounds/envil.wav"},
    // {SOUND_HIT, "assets/sounds/hit.wav"},
    // {SOUND_DEATH, "assets/sounds/death.wav"},
    // {SOUND_WIN, "assets/sounds/win.wav"},
    // {SOUND_LOSE, "assets/sounds/lose.wav"},
    // {SOUND_MENU, "assets/sounds/menu.wav"},
    // {SOUND_GAME, "assets/sounds/game.wav"},
    // {SOUND_END, "assets/sounds/end.wav"},
};

void initSounds(game_t *game)
{
    sound_t *sound = NULL;

    InitAudioDevice();
    game->sound = list_create();
    for (int i = 0; i < sizeof(relation) / sizeof(relation_t); i++) {
        sound = calloc(1, sizeof(sound_t));
        sound->type = relation[i].type;
        sound->sound = LoadSound(relation[i].path);
        SetSoundVolume(sound->sound, 0.2f);
        list_push_data(game->sound, sound);
    }
}
