#include "raylib.h"
#include "player.h"
#include <iostream>

const int RES_X = 1920;
const int RES_Y = 1080;

void HandleInput(Player *player)
{
    if (IsKeyPressed(KEY_W))
    {
        player->shape->y -= 100;
    }

    if (IsKeyPressed(KEY_S))
    {
        player->shape->y += 100;
    }
}

int main()
{
    InitWindow(RES_X, RES_Y, "Best Pong Ever");
    Player *player = new Player(50, 150, (RES_X / 2) - 500, (RES_Y / 2) + 200, BLACK);
    
    while(!WindowShouldClose())
    {
        HandleInput(player);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            player->Render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
