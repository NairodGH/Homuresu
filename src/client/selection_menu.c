#include "includes.h"

void add_back(menu_t *menu_st);

void selection_menu_loop(menu_t *menu)
{
    BeginDrawing();

    DrawTextureEx(menu->title, (Vector2){GetScreenWidth() - menu->title.width / 2, 10}, 0.0f, 0.5f, WHITE);

    DrawRectangle(10, 50, 500, 150, BLACK);
    DrawRectangleLines(10, 50, 500, 150, WHITE);
    DrawText("Selection Menu:", 25, 80, 20, WHITE);
    DrawText("Press LEFT/RIGHT to change selection", 70, 120, 20, WHITE);
    DrawText("Press SPACE to select", 70, 140, 20, WHITE);
    DrawText("Press ESC to go back", 70, 160, 20, WHITE);

    menu->camera.target = (Vector3){ 20.0f, 0.0f, 0.0f };
    BeginMode3D(menu->camera);
    DrawModelEx(*(Model *)menu->selection_menu->current->data, (Vector3){ 10.0f, 0.0f, 0.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, 90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
    EndMode3D();

    if (IsKeyPressed(KEY_RIGHT)) {
        if (menu->selection_menu->current->next != NULL)
            menu->selection_menu->current = menu->selection_menu->current->next;
    } else if (IsKeyPressed(KEY_LEFT)) {
        if (menu->selection_menu->current->prev != NULL)
            menu->selection_menu->current = menu->selection_menu->current->prev;
    }

    menu->mousePoint = GetMousePosition();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    DrawCircle(menu->mousePoint.x, menu->mousePoint.y, 5, BLACK);
    EndDrawing();
}
