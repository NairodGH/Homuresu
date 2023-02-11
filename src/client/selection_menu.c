#include "includes.h"

void add_back(menu_t *menu_st);

void selection_menu_loop(menu_t *menu)
{
    BeginDrawing();
    DrawText("Selection Menu", 10, 10, 20, BLACK);
    DrawText("Press ESC to return to main menu", 10, 40, 20, BLACK);
    DrawTextureEx(menu->title, (Vector2){50, 50}, 0.0f, 0.5f, WHITE);
    EndDrawing();
}
