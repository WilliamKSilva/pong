#include "ball.h"
#include "opponent.h"
#include "player.h"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

const int RES_X = 1920;
const int RES_Y = 1080;

const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 150;

const int SCORE_POS_X = 10;
const int SCORE_POS_Y = 20;

struct OutOfBounds {
  bool right;
  bool out;
};

OutOfBounds GameObjectOutOfBounds(Vector2 position) {
  bool left = position.x <= 0;
  bool right = position.x >= 1920;

  return OutOfBounds{right, left || right};
}
bool TopAndBottomCollision(Vector2 position) {
  return position.y <= 0 || position.y >= 1080;
}

int main() {
  InitWindow(RES_X, RES_Y, "Best Pong Ever");
  Player *player = new Player(RECT_WIDTH, RECT_HEIGHT, (RES_X / 2) - 800,
                              (RES_Y / 2) + 100, BLACK);

  SetTargetFPS(60);

  Ball *ball = new Ball(RES_X / 2, RES_Y / 2, 20, BLACK);
  ball->speed.x = 14.0f;
  ball->speed.y = 8.0f;

  Opponent *opponent =
      new Opponent({(RES_X / 2.0) + 800, (RES_Y / 2.0) + 100}, {3.0f, 5.0f},
                   RECT_WIDTH, RECT_HEIGHT, BLACK);

  ToggleFullscreen();

  while (!WindowShouldClose()) {
    // Update
    player->HandleInput();
    CollisionTopAndBottom topBottomCollision = ball->TopAndBottomCollision();
    OutOfBounds ballOutOfBounds = GameObjectOutOfBounds(ball->position);

    if (ballOutOfBounds.right) {
      player->UpdateScore();
    }

    if (ballOutOfBounds.out) {
      ball->ResetPosition();
    }

    CollisionObject playerCollision = ball->ObjectCollision(
        Rectangle{player->position.x, player->position.y, (float)player->width,
                  (float)player->height});

    if (playerCollision.collide) {
      CollisionObject *collisionObject = new CollisionObject();
      collisionObject->collide = playerCollision.collide;
      collisionObject->point = playerCollision.point;
      collisionObject->movingLeft = playerCollision.movingLeft;
      ball->topBottomCollision = NULL;
      ball->objectCollision = collisionObject;
    }

    CollisionObject opponentCollision = ball->ObjectCollision(
        Rectangle{opponent->position.x, opponent->position.y,
                  (float)opponent->width, (float)opponent->height});

    if (opponentCollision.collide) {
      CollisionObject *collisionObject = new CollisionObject();
      collisionObject->collide = opponentCollision.collide;
      collisionObject->point = opponentCollision.point;
      collisionObject->movingLeft = opponentCollision.movingLeft;
      ball->topBottomCollision = NULL;
      ball->objectCollision = collisionObject;
    }

    if (topBottomCollision.collide) {
      CollisionTopAndBottom *topBottom = new CollisionTopAndBottom();
      topBottom->point = topBottomCollision.point;
      topBottom->collide = topBottomCollision.collide;
      topBottom->top = topBottomCollision.top;
      topBottom->movingLeft = topBottomCollision.movingLeft;
      ball->objectCollision = NULL;
      ball->topBottomCollision = topBottom;
    }

    ball->Move();
    opponent->Move(ball->position);
    //

    // Draw
    BeginDrawing();
      ClearBackground(RAYWHITE);
      std::string score = std::to_string(player->score);
      std::string scoreText = "SCORE: " + score; 
      DrawText(scoreText.data(), SCORE_POS_X, SCORE_POS_Y, 35, BLACK);
      player->Render();
      opponent->Render();
      ball->Render();
    EndDrawing();
    //
  }


  CloseWindow();

  return 0;
}
