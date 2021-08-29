#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 360
#define FRAMES_PER_SECOND 60
#define GRAVITY 1 //  Acceleration due to gravity (Pixel/Frame)/Frame
#define JUMP_VELOCITY -20

void DrawGameWindow()
{
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Jumping the Unknown");
}

void StartGame()
{
    const int width = 50;
    const int height = 80;

    bool isInAir = false;

    int posY = CANVAS_HEIGHT - height;
    int velocity = 0;

    SetTargetFPS(FRAMES_PER_SECOND);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (posY >= CANVAS_HEIGHT - height)
        {
            velocity = 0;
            isInAir = false;
        }
        else
        {
            velocity += GRAVITY;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += JUMP_VELOCITY;
        }

        posY += velocity;
        DrawRectangle(CANVAS_WIDTH / 2, posY, width, height, BLUE);

        EndDrawing();
    }
}

int main()
{
    DrawGameWindow();
    StartGame();
    CloseWindow();
}