#include "includes.h"

static void initSelectionMenu(game_t *game)
{
}

void initMenu(game_t *game)
{
    game->menu = calloc(1, sizeof(menu_t));
    game->menu->button = LoadTexture("./ressources/button.png");
    game->menu->button.width *= 5;
    game->menu->button.height *= 5;
    game->menu->sourceRec = (Rectangle){ 0, 0, (float)game->menu->button.width / 2, game->menu->button.height};

    game->menu->btnBounds = (Rectangle){ (GetMonitorWidth(GetCurrentMonitor()) / 2) - (game->menu->button.width / 3),
    (GetMonitorHeight(GetCurrentMonitor()) - game->menu->button.height) - 50, game->menu->button.width / 2, game->menu->button.height};

    game->menu->quit_button = LoadTexture("./ressources/quit_button.png");
    game->menu->quit_button.width *= 5;
    game->menu->quit_button.height *= 5;
    game->menu->quit_sourceRec = (Rectangle){ 0, 0, (float)game->menu->quit_button.width / 2, game->menu->quit_button.height};

    game->menu->quit_position = (Vector2){((GetMonitorWidth(GetCurrentMonitor()) - game->menu->quit_button.width / 2)),
    0};

    game->menu->quit_btnBounds = (Rectangle){game->menu->quit_position.x,
    game->menu->quit_position.y, game->menu->quit_button.width / 2, game->menu->quit_button.height};

    game->menu->mousePoint = (Vector2){ 0.0f, 0.0f };
    game->menu->camera = (Camera){ 0 };
    game->menu->camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    game->menu->camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    game->menu->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->menu->camera.fovy = 60.0f;
    game->menu->camera.projection = CAMERA_PERSPECTIVE;

    game->menu->is_menu = 1;

    game->menu->title = LoadTexture("./ressources/title_homuresu.png");
    game->menu->title.width *= 4;
    game->menu->title.height *= 4;

    game->menu->windowSize = game->windowSize;
}
