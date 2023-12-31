#include "raylib.h" 
#include "raymath.h"
#include "opponent.h"
#include <iostream>

Opponent::Opponent(Vector2 position, Vector2 speed, int width, int height, Color color)
{
  this->position.x = position.x;
  this->position.y = position.y;
  this->speed.x = speed.x;
  this->speed.y = speed.y;
  this->width = width;
  this->height = height;
  this->color = color;
}

void Opponent::Render()
{
  DrawRectangle(this->position.x, this->position.y, this->width, this->height, this->color);
}

void Opponent::Move(Vector2 ballPosition)
{
  Vector2 newPosition = Vector2Zero();
  newPosition.y = this->position.y;

  // Object going out of bounds
  if (ballPosition.y >= 1080)
  {
    return;
  }

  if (ballPosition.y >= newPosition.y) {
    newPosition.y += this->speed.y;
  } else {
    newPosition.y -= this->speed.y;
  }

  this->position.y = newPosition.y;
}
