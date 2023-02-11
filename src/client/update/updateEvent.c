#include "includes.h"

typedef struct {
    KeyboardKey key;
    void (*func)(game_t *game);
} binding_t;

static const binding_t bindings[] = {
    {KEY_ENTER, updateEnter},
    {KEY_W, updateWalk}
};

static void updateBinding(game_t *game)
{
    for (size_t i = 0; i < sizeof(bindings) / sizeof(bindings[0]); i++) {
        if (IsKeyPressed(bindings[i].key)) {
            bindings[i].func(game);
        }
    }
}

void updateEvent(game_t *game)
{
    updateBinding(game);
}
