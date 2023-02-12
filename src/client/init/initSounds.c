#include "includes.h"

#include <unistd.h>
typedef struct {
    sound_e type;
    const char *path;
} relation_t;

static const relation_t relation[] = {
    {SOUND_WALK, "assets/sounds/walk.wav"},
    {SOUND_COLLISION_WALL, "assets/sounds/collision_wall.wav"},
    {SOUND_SHOT, "assets/sounds/shot.wav"},
};

void initSounds(game_t *game)
{
    sound_t *sound = NULL;

    game->sound = list_create();
    for (size_t i = 0; i < sizeof(relation) / sizeof(relation_t); i++) {
        sound = calloc(1, sizeof(sound_t));
        sound->type = relation[i].type;
        sound->sound = LoadMusicStream(relation[i].path);
        SetMusicVolume(sound->sound, 0.2f);
        list_push_data(game->sound, sound);
    }
}
