#include "includes.h"

typedef struct {
    KeyboardKey key;
    void (*func)(game_t *game);
} binding_t;

static const binding_t bindings[] = {
    {KEY_ENTER, updateEnter},
    {KEY_W, updateWalk},
    {KEY_A, updateWalk},
    {KEY_S, updateWalk},
    {KEY_D, updateWalk},
    {KEY_R, updateR},
};

static void updateBinding(game_t *game)
{
    for (size_t i = 0; i < sizeof(bindings) / sizeof(bindings[0]); i++) {
        if (IsKeyDown(bindings[i].key)) {
            bindings[i].func(game);
        }
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        updateEnter(game);
    }
}

void updateEvent(game_t *game)
{
    updateBinding(game);
}
