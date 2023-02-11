#include "includes.h"

static void menu_ui(menu_t *menu_st)
{
    BeginDrawing();
    menu_st->mousePoint = GetMousePosition();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    DrawCircle(menu_st->mousePoint.x, menu_st->mousePoint.y, 50, RED);
    menu_st->btnStartAction = false;
    menu_st->sourceRec = (Rectangle){ 0, 0, (float)menu_st->button.width / 2, menu_st->button.height};
    DrawTextureRec(menu_st->button, menu_st->sourceRec, (Vector2){((GetMonitorWidth(GetCurrentMonitor()) / 2) - (menu_st->button.width / 3)), (GetMonitorHeight(GetCurrentMonitor()) - menu_st->button.height) - 50}, WHITE);

    if (CheckCollisionPointRec(menu_st->mousePoint, menu_st->btnBounds)) {
        menu_st->sourceRec.x += menu_st->button.width / 2;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) menu_st->btnStartState = 2;
        else menu_st->btnStartState = 1;
    }
    else menu_st->btnStartState = 0;

    DrawTextureEx(menu_st->title, (Vector2){(GetMonitorWidth(GetCurrentMonitor()) - menu_st->title.width) / 2, 50}, 0.0f, 1.0f, WHITE);
    EndDrawing();
}

static void add_back(menu_t *menu_st)
{
    BeginMode3D(menu_st->camera);
    ClearBackground(RAYWHITE);
    DrawCube((Vector3){ -16.0f, 2.5f, -15.0f }, 1.0f, 5.0f, 32.0f, BLUE);   // Draw a blue wall
    DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
    DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall
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
        menu_st->camera.target = (Vector3){ 0.0f, 1.8f, 0.0f};
        x += 0.1f;
    }
    return (0);
}
