#include <math.h>
#include "includes.h"

static void menu_ui(menu_t *menu_st)
{
    BeginDrawing();

    DrawTextureRec(menu_st->button, menu_st->sourceRec, (Vector2){((GetMonitorWidth(GetCurrentMonitor()) / 2) - (menu_st->button.width / 3)),
    (GetMonitorHeight(GetCurrentMonitor()) - menu_st->button.height) - 50}, WHITE);

    if (CheckCollisionPointRec(menu_st->mousePoint, menu_st->btnBounds)) {
        menu_st->sourceRec.x = menu_st->button.width / 2;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // todo
        }
    } else {
        menu_st->sourceRec.x = 0;
    }

    DrawTextureRec(menu_st->quit_button, menu_st->quit_sourceRec, (Vector2){menu_st->quit_position.x, menu_st->quit_position.y}, WHITE);

    if (CheckCollisionPointRec(menu_st->mousePoint, menu_st->quit_btnBounds)) {
        menu_st->quit_sourceRec.x = menu_st->quit_button.width / 2;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu_st->quit_position.x = rand() % (GetMonitorWidth(GetCurrentMonitor()) - menu_st->quit_button.width / 2);
            menu_st->quit_position.y = rand() % (GetMonitorHeight(GetCurrentMonitor()) - menu_st->quit_button.height);
            menu_st->quit_btnBounds = (Rectangle){menu_st->quit_position.x, menu_st->quit_position.y, menu_st->quit_button.width / 2, menu_st->quit_button.height};
        }
    } else {
        menu_st->quit_sourceRec.x = 0;
    }

    DrawTextureEx(menu_st->title, (Vector2){(GetMonitorWidth(GetCurrentMonitor()) - menu_st->title.width) / 2, 50}, 0.0f, 1.0f, WHITE);

    menu_st->mousePoint = GetMousePosition();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    DrawCircle(menu_st->mousePoint.x, menu_st->mousePoint.y, 5, BLACK);
    EndDrawing();
}

static void add_back(menu_t *menu_st)
{
    Texture2D texture = LoadTexture("./resources/immeuble/immeuble1.png");
    BeginMode3D(menu_st->camera);
    ClearBackground(SKYBLUE);

    //Draw Walls
    DrawCubeTexture(texture, (Vector3){ 0.0f, 0.0f, -25.0f }, 50.0f, 20.0f, 0.1f, WHITE);
    DrawCubeTexture(texture, (Vector3){ 0.0f, 0.0f, 25.0f }, 50.0f, 20.0f, 0.1f, WHITE);
    DrawCubeTexture(texture, (Vector3){ -25.0f, 0.0f, 0.0f }, 0.1f, 20.0f, 50.0f, WHITE);
    DrawCubeTexture(texture, (Vector3){ 25.0f, 0.0f, 0.0f }, 0.1f, 20.0f, 50.0f, WHITE);
    DrawCube((Vector3){ 0.0f, 0.0f, 0.0f }, 50.0f, 0.1f, 50.0f, DARKGREEN);
    EndMode3D();
}

int menu(menu_t *menu_st)
{
    float x = 0;

    while (menu_st->is_menu == 1) {
        if (IsKeyPressed(KEY_ENTER))
            menu_st->is_menu = 0;
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        add_back(menu_st);
        menu_ui(menu_st);
        menu_st->camera.target = (Vector3){sinf(x) * 15.0f, 1.8f, cosf(x) * 15.0f};
        x += 0.01f;
    }
    return (0);
}
