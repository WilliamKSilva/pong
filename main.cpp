#include "raylib.h"
#include "player.h"
#include "ball.h"
#include <iostream>

const int RES_X = 1920;
const int RES_Y = 1080;

const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 150;

void HandleInput(Player *player)
{
    if (IsKeyPressed(KEY_W))
    {
        player->shape.y -= 100;
    }

    if (IsKeyPressed(KEY_S))
    {
        player->shape.y += 100;
    }
}

void HandleBallMovement(Ball *ball)
{
    if (IsKeyPressed(KEY_LEFT))
    {
        ball->position.x -= 100;
    }

    if (IsKeyPressed(KEY_RIGHT))
    {
        ball->position.x += 100;
    }
}

int main()
{
    InitWindow(RES_X, RES_Y, "Best Pong Ever");
    Player *player = new Player(RECT_WIDTH, RECT_HEIGHT, (RES_X / 2) - 500, (RES_Y / 2) + 100, BLACK);

    Rectangle *opponent = new Rectangle(); 
    opponent->x = (RES_X / 2) + 500;
    opponent->y = (RES_Y / 2) + 100;
    opponent->width = RECT_WIDTH;
    opponent->height = RECT_HEIGHT;

    Ball *ball = new Ball(RES_X / 2, RES_Y / 2, 50, BLACK);
    
    while(!WindowShouldClose())
    {
        HandleInput(player);
        HandleBallMovement(ball);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(opponent->x, opponent->y, opponent->width, opponent->height, BLACK);
            ball->Render();
            Collision collision = ball->DetectCollision(player->shape);
            if (collision.collide)
            {
            std::cout << "asiudhisaud" << std::endl;
            }
            
            player->Render();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
