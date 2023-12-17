#include "ball.h"
#include <iostream>
#include <raylib.h>
#include <raymath.h>

Ball::Ball(int x, int y, float radius, Color color) {
  this->position.x = x;
  this->position.y = y;
  this->radius = radius;
  this->color = color;
  this->objectCollision = NULL;
  this->topBottomCollision = NULL;
}

void Ball::Render() { DrawCircleV(position, radius, color); }

void Ball::Move() {
  Vector2 newPosition = Vector2Zero();
  newPosition.x = this->position.x;
  newPosition.y = this->position.y;

  bool right = this->position.x >= GetScreenWidth() / 2.0;

  // If has an Object Collision will bounce to the opposite direction
  if (objectCollision != NULL) {

    // X Axis
    if (objectCollision->movingLeft) {
      newPosition.x -= this->speed.x;
    } else {
      newPosition.x += this->speed.x;
    }

    // Y Axis
    if (objectCollision->point.y <= -15) {
      newPosition.y += this->speed.y;
    }

    if (objectCollision->point.y >= 18) {
      newPosition.y -= this->speed.y;
    }
  } else {
  }

  // First movement
  if (objectCollision == NULL && topBottomCollision == NULL)
  {
    newPosition.x -= this->speed.x;
  }

  if (topBottomCollision != NULL)
  {
    if (topBottomCollision->top)
    {
      newPosition.y += this->speed.y;
    } else {
      newPosition.y -= this->speed.y;
    }

    if (topBottomCollision->movingLeft)
    {
      newPosition.x -= this->speed.x;
    } else {
      newPosition.x += this->speed.x;
    }
  }

  this->position.x = newPosition.x;
  this->position.y = newPosition.y;
}

CollisionObject Ball::ObjectCollision(Rectangle rec) {
  bool right = this->position.x >= GetScreenWidth() / 2.0;
  Vector2 center = Vector2AddValue(this->position, this->radius);
  Vector2 recHalfExtent = Vector2({rec.width / 2.0f, rec.height / 2.0f});
  Vector2 recCenter =
      Vector2({rec.x + recHalfExtent.x, rec.y + recHalfExtent.y});
  Vector2 difference = Vector2Subtract(center, recCenter);
  Vector2 clamped =
      Vector2Clamp(difference, Vector2Negate(recHalfExtent), recHalfExtent);

  Vector2 closest = Vector2Add(recCenter, clamped);
  difference = Vector2Subtract(closest, center);
  bool collide = Vector2Length(difference) < this->radius;

  return CollisionObject{collide, right, clamped};
}

CollisionTopAndBottom Ball::TopAndBottomCollision() {
  bool movingRight = false;

  if (objectCollision != NULL)
  {
    movingRight = objectCollision->movingLeft; 
  }

  bool top = this->position.y <= 0;
  bool bottom = this->position.y >= 1080;

  if (top) {
    return CollisionTopAndBottom{
        {this->position.x, this->position.y}, movingRight, true, true};
  }

  if (bottom) {
    return CollisionTopAndBottom{
        {this->position.x, this->position.y}, movingRight, false, true};
  }

  return CollisionTopAndBottom{
      {this->position.x, this->position.y}, movingRight, false, false};
}

void Ball::ResetPosition()
{
  position.x = 1920 / 2.0 + 10;
  position.y = 1080 / 2.0;
  this->objectCollision = NULL;
  this->topBottomCollision = NULL;
}
