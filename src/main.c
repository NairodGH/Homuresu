#include "raylib.h"
#include "raymath.h"

#define MAX_COLUMNS 20

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetTraceLogLevel(LOG_NONE);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    Model model = LoadModel("resources/Maxwell.glb");
    Model model2 = LoadModel("resources/Dorion.glb");
    Model model3 = LoadModel("resources/Batarang.obj");
    Texture2D texture = LoadTexture("resources/Whiskers.png");
    Texture2D texture2 = LoadTexture("resources/Maxwell.png");
    Texture2D texture3 = LoadTexture("resources/Dorion.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    model.materials[1].maps[MATERIAL_MAP_DIFFUSE].texture = texture2;
    model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture3;
    model2.transform = MatrixMultiply(model2.transform, MatrixRotate((Vector3){0.0f, 0.0f, 1.0f}, 270.0f * DEG2RAD));

    Camera camera = {0};
    camera.position = (Vector3){4.0f, 2.0f, 4.0f};
    camera.target = (Vector3){0.0f, -1.8f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawPlane((Vector3){0.0f, 0.0f, 0.0f}, (Vector2){32.0f, 32.0f}, LIGHTGRAY); // Draw ground
        DrawCube((Vector3){-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);           // Draw a blue wall
        DrawCube((Vector3){16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);            // Draw a green wall
        DrawCube((Vector3){0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);            // Draw a yellow wall

        DrawModel(model, (Vector3){0.0f, 2.0f, 0.0f}, 1.0f, WHITE); // Draw 3d model with texture
        DrawModel(model2, (Vector3){3.0f, 0.0f, 0.0f}, 1.0f, WHITE); // Draw 3d model with texture
        DrawModel(model3, (Vector3){-5.0f, 1.0f, 0.0f}, 5.0f, WHITE); // Draw 3d model with texture

        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
