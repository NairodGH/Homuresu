#include "includes.h"

typedef struct {
    KeyboardKey key;
    void (*func)(game_t *game);
} keybind_t;

typedef struct {
    MouseButton button;
    void (*func)(game_t *game);
} mousebind_t;

static const keybind_t keybinds[] = {
    {KEY_LEFT_SHIFT, sprint},
    {KEY_SPACE, jump}
};

static const mousebind_t mousebinds[] = {
    {MOUSE_BUTTON_LEFT, shoot},
};

static void updateBindings(game_t *game)
{
    for (size_t i = 0; i < sizeof(keybinds) / sizeof(keybinds[0]); i++)
        if (IsKeyPressed(keybinds[i].key))
            keybinds[i].func(game);
    for (size_t i = 0; i < sizeof(mousebinds) / sizeof(mousebinds[0]); i++)
        if (IsMouseButtonPressed(mousebinds[i].button))
            mousebinds[i].func(game);
}

void updateEvent(game_t *game)
{
    updateBindings(game);
    // if (game->jump != 1.0f) {
        game->camera.position.y += 0.1f;
        // game->jump -= 0.1;
    // }
    // if (game->jump < -1.0f)
    //     game->jump = 1.0f;
    printf("%f %f %f\n", game->camera.position.x, game->camera.position.y, game->camera.position.z);
}
