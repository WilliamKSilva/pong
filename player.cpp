#include "raylib.h"
#include "player.h"
#include <iostream>

Player::Player(int width, int height, int posX, int posY, Color color) {
  shape = new Rectangle();
  shape->x = posX;
  shape->y = posY;
  shape->width = width;
  shape->height = height;
  color = color;
};

void Player::Render()
{
  DrawRectangle(shape->x, shape->y, shape->width, shape->height, BLACK);
}
