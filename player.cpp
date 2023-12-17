#include "raylib.h"
#include "player.h"

Player::Player(int width, int height, int posX, int posY, Color color) {
  this->position.x = posX;
  this->position.y = posY;
  this->width = width;
  this->height = height;
  this->color = color;
  this->score = 0;
};

void Player::Render()
{
  DrawRectangle(this->position.x, this->position.y, this->width, this->height, this->color);
}

void Player::HandleInput() {
  if (IsKeyDown(KEY_W)) {
    this->position.y -= 10;
  }

  if (IsKeyDown(KEY_S)) {
    this->position.y += 10;
  }
}

void Player::UpdateScore() {
  this->score += 1;
}
