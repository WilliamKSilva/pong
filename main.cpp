#include "raylib.h"
#include "player.h"
#include <iostream>

const int RES_X = 1920;
const int RES_Y = 1080;

int main()
{
    InitWindow(RES_X, RES_Y, "Best Pong Ever");

    Player *player = new Player(100, 100, (RES_X / 2) - 200, (RES_Y / 2) + 200, BLACK);
    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            player->Render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
