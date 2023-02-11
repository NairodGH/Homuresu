#include "includes.h"

typedef struct {
    KeyboardKey key;
    void (*func)(game_t *game, bool isPressed);
} keybind_t;

typedef struct {
    MouseButton button;
    void (*func)(game_t *game, bool isPressed);
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
    for (size_t i = 0; i < sizeof(keybinds) / sizeof(keybinds[0]); i++) {
        if (IsKeyPressed(keybinds[i].key))
            keybinds[i].func(game, true);
        if (IsKeyReleased(keybinds[i].key))
            keybinds[i].func(game, false);
    }
    for (size_t i = 0; i < sizeof(mousebinds) / sizeof(mousebinds[0]); i++) {
        if (IsMouseButtonPressed(mousebinds[i].button))
            mousebinds[i].func(game, true);
        if (IsMouseButtonReleased(mousebinds[i].button))
            mousebinds[i].func(game, false);
    }
}

void updateEvent(game_t *game)
{
    updateBindings(game);
    if (game->height != 1.0f) {
        game->camera.position.y += game->height;
        game->camera.target.y = game->camera.position.y;
        game->height += (game->gravity -= 0.1f);
        if (game->gravity < -1.0f)
            game->height = game->gravity = 1.0f;
    }
    game->camera.position.x += (game->camera.position.x - game->cameraLastPosition.x) * game->speed * 1.5;
    game->camera.position.z += (game->camera.position.z - game->cameraLastPosition.z) * game->speed * 1.5;
    printf("%f %f %f %f %f %f\n", game->camera.position.x, game->camera.position.y, game->camera.position.z, game->camera.target.x, game->camera.target.y, game->camera.target.z);
}
