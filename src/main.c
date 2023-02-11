#include "raylib.h"
#include "../include/menu.h"
#include <stdlib.h>

#define MAX_COLUMNS 20
int menu(menu_t *menu_st);

static void init_menu(menu_t *menu_st)
{
    menu_st->button = LoadTexture("./ressources/button.png"); // Load button texture
    menu_st->button.width *= 5;
    menu_st->button.height *= 5;
    menu_st->frameHeight = (float)menu_st->button.height / 3;
    menu_st->sourceRec = (Rectangle){ 0, 0, (float)menu_st->button.width / 2, menu_st->button.height};

    menu_st->btnBounds = (Rectangle){ ((GetScreenWidth() / 2) - (menu_st->button.width / 4)), (GetScreenHeight() - menu_st->button.height) / 2, menu_st->button.width, menu_st->frameHeight };

    menu_st->btnStartState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    menu_st->btnStartAction = false;         // Button action should be activated

    menu_st->mousePoint = (Vector2){ 0.0f, 0.0f };
    menu_st->camera = (Camera){ 0 };
    menu_st->camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    menu_st->camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    menu_st->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    menu_st->camera.fovy = 60.0f;
    menu_st->camera.projection = CAMERA_PERSPECTIVE;

    menu_st->is_menu = 1;

    menu_st->title = LoadTexture("./ressources/title_homuresu.png");
    menu_st->title.width *= 4;
    menu_st->title.height *= 4;
}

int main_loop(Camera camera)
{
    float heights[MAX_COLUMNS] = { 0 };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++) {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = (Vector3){ (float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
    }

    while (1) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
        DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
        DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
        DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

        // Draw some cubes around
        for (int i = 0; i < MAX_COLUMNS; i++) {
            DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
            DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
        }
        EndMode3D();
        DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines( 10, 10, 220, 70, BLUE);
        DrawText("First person camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
        EndDrawing();
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
    }
    return 0;
}

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "yeeet");

    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);
    menu_t *menu_st = malloc(sizeof(menu_t));
    init_menu(menu_st);
    while (1) {
        UpdateCamera(&camera);
        (menu_st->is_menu == 1) ? menu(menu_st) : 0;
        if (menu_st->is_menu == 0 && main_loop(camera) == 0)
            menu_st->is_menu = 1;
        if (IsKeyPressed(KEY_ESCAPE)) {
            break;
        }
    }
    CloseWindow();
    return 0;
}
