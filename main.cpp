#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 360
#define FRAMES_PER_SECOND 60
#define GRAVITY 1000 //  Acceleration due to gravity (Pixel/Frame)/s
#define JUMP_VELOCITY -600
#define ANIMATION_FRAME_TIME 0.08

void DrawGameWindow()
{
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Jumping the Unknown");
}

void StartGame()
{
    Texture2D scarfySpriteSheet = LoadTexture("textures/scarfy.png");

    Rectangle scarfyRec;
    scarfyRec.width = scarfySpriteSheet.width / 6;
    scarfyRec.height = scarfySpriteSheet.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = CANVAS_WIDTH * 0.2;
    scarfyPos.y = CANVAS_HEIGHT - scarfyRec.height;

    int frame = 0;
    float timeToNextAnimationFrame;

    bool isInAir = false;

    int velocity = 0;

    SetTargetFPS(FRAMES_PER_SECOND);
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        if (scarfyPos.y >= CANVAS_HEIGHT - scarfyRec.height)
        {
            velocity = 0;
            isInAir = false;
        }
        else
        {
            velocity += GRAVITY * deltaTime;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += JUMP_VELOCITY;
        }

        scarfyPos.y += velocity * deltaTime;

        scarfyRec.x = frame * scarfyRec.width;

        timeToNextAnimationFrame += deltaTime;
        if (timeToNextAnimationFrame >= ANIMATION_FRAME_TIME && !isInAir)
        {
            timeToNextAnimationFrame = 0;
            frame++;

            if (frame == 5)
            {
                frame = 0;
            }
        }

        DrawTextureRec(scarfySpriteSheet, scarfyRec, scarfyPos, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfySpriteSheet);
}

int main()
{
    DrawGameWindow();
    StartGame();

    CloseWindow();
}