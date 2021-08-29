#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 480

void DrawGameWindow()
{
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Jumping the Unknown");
}

void StartGame()
{
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
}

int main()
{
    DrawGameWindow();
    StartGame();
}