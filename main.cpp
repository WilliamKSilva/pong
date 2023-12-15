#include "ball.h"
#include "opponent.h"
#include "player.h"
#include "raylib.h"
#include <iostream>

const int RES_X = 1920;
const int RES_Y = 1080;

const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 150;

void HandleInput(Player *player) {
  if (IsKeyDown(KEY_W)) {
    player->shape.y -= 10;
  }

  if (IsKeyDown(KEY_S)) {
    player->shape.y += 10;
  }
}

bool GameObjectOutOfBounds(Vector2 position) { return position.x <= 0; }
void ResetGameObjectPosition(Vector2 &position) {
  position.x = RES_X / 2.0 + 10;
}

// TODO: Bounce on the top and bottom of screen 

int main() {
  InitWindow(RES_X, RES_Y, "Best Pong Ever");
  Player *player = new Player(RECT_WIDTH, RECT_HEIGHT, (RES_X / 2) - 800,
                              (RES_Y / 2) + 100, BLACK);

  SetTargetFPS(60);

  Ball *ball = new Ball(RES_X / 2, RES_Y / 2, 20, BLACK);
  ball->speed.x = 4.0f;
  ball->speed.y = 2.0f;
  ball->lastCollision = NULL;

  Opponent *opponent =
      new Opponent({(RES_X / 2.0) + 800, (RES_Y / 2.0) + 100}, {2.0f, 4.0f},
                   RECT_WIDTH, RECT_HEIGHT, BLACK);

  while (!WindowShouldClose()) {
    // Update
    HandleInput(player);
    Collision collision = ball->DetectCollision(player->shape);

    if (GameObjectOutOfBounds(ball->position)) {
      ResetGameObjectPosition(ball->position);
    }

    if (!collision.collide) {
      ball->Move();
    } else {
      bool right = ball->position.x >= GetScreenWidth() / 2.0;
      Collision *lastCollision = new Collision();
      lastCollision->point = {collision.point.x, collision.point.y};
      lastCollision->right = collision.right;
      ball->lastCollision = lastCollision;

      ball->Move();
    }
    //

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);
    player->Render();
    opponent->Render();
    ball->Render();
    EndDrawing();
    //
  }

  CloseWindow();

  return 0;
}
