#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Best Pong Ever");
    BeginDrawing();
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello Pong!", 400, 300, 21, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
