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
bool TopAndBottomCollision(Vector2 position) {
  return position.y <= 0 || position.y >= 1080;
}
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
  ball->speed.x = 8.0f;
  ball->speed.y = 4.0f;

  Opponent *opponent =
      new Opponent({(RES_X / 2.0) + 800, (RES_Y / 2.0) + 100}, {2.0f, 4.0f},
                   RECT_WIDTH, RECT_HEIGHT, BLACK);

  while (!WindowShouldClose()) {
    // Update
    HandleInput(player);
    CollisionObject objectCollision = ball->ObjectCollision(player->shape);
    CollisionTopAndBottom topBottomCollision = ball->TopAndBottomCollision();

    if (GameObjectOutOfBounds(ball->position)) {
      ResetGameObjectPosition(ball->position);
    }

    if (objectCollision.collide)
    {
      CollisionObject *collisionObject = new CollisionObject();
      collisionObject->collide = objectCollision.collide;
      collisionObject->point = objectCollision.point;
      collisionObject->movingLeft = objectCollision.movingLeft;
      ball->topBottomCollision = NULL;
      ball->objectCollision = collisionObject;
    }

    if (topBottomCollision.collide)
    {
      CollisionTopAndBottom *topBottom = new CollisionTopAndBottom(); 
      topBottom->point = topBottomCollision.point;
      topBottom->collide = topBottomCollision.collide;
      topBottom->top = topBottomCollision.top;
      topBottom->movingLeft = topBottomCollision.movingLeft;
      ball->objectCollision = NULL;
      ball->topBottomCollision = topBottom;
    }

    ball->Move();
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
