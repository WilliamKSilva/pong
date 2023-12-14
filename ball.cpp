#include "ball.h"
#include <iostream>
#include <raylib.h>
#include <raymath.h>

Ball::Ball(int x, int y, float radius, Color color) {
  this->position.x = x;
  this->position.y = y;
  this->radius = radius;
  this->color = color;
}

void Ball::Render() { DrawCircleV(position, radius, color); }

void Ball::Move() {
  Vector2 newPosition = Vector2Zero();
  newPosition.x = this->position.x;
  newPosition.y = this->position.y;

  // X axis
  bool right = this->position.x >= GetScreenWidth() / 2.0;

  // If has an lastCollision will bounce to the opposite direction
  if (lastCollision != NULL) {
    if (right) {
      newPosition.x -= this->speed.x;
    } else {
      newPosition.x += this->speed.x;
    }
  } else {
    newPosition.x -= this->speed.x;
  }

  // Y axis
  if (lastCollision != NULL) {
    if (lastCollision->point.y <= -15) {
      newPosition.y += this->speed.y;
    }

    if (lastCollision->point.y >= 15) {
      newPosition.y -= this->speed.y;
    }
  }

  this->position.x = newPosition.x;
  this->position.y = newPosition.y;
}

Collision Ball::DetectCollision(Rectangle rec) {
  Vector2 center = Vector2AddValue(this->position, this->radius);
  Vector2 recHalfExtent = Vector2({rec.width / 2.0f, rec.height / 2.0f});
  Vector2 recCenter =
      Vector2({rec.x + recHalfExtent.x, rec.y + recHalfExtent.y});
  Vector2 difference = Vector2Subtract(center, recCenter);
  Vector2 clamped =
      Vector2Clamp(difference, Vector2Negate(recHalfExtent), recHalfExtent);

  Vector2 closest = Vector2Add(recCenter, clamped);
  difference = Vector2Subtract(closest, center);
  bool collide = Vector2Length(difference) <= this->radius;
  return Collision{collide, clamped};
}
