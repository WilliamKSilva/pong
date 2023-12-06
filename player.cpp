#include "raylib.h"
#include "player.h"

Player::Player(int width, int height, int posX, int posY, Color color) {
  this->shape.x = posX;
  this->shape.y = posY;
  this->shape.width = width;
  this->shape.height = height;
  this->color = color;
};

void Player::Render()
{
  DrawRectangle(shape.x, shape.y, shape.width, shape.height, color);
}
