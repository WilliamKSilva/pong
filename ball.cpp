#include "ball.h"
#include <raylib.h>
#include <raymath.h>

Ball::Ball(int x, int y, float radius, Color color)
{
    this->position.x = x;
    this->position.y = y;
    this->radius = radius;
    this->color = color;
}

void Ball::Render()
{
    DrawCircleV(position, radius, color);
}

Collision Ball::DetectCollision(Rectangle rec)
{
    Vector2 center = Vector2AddValue(this->position, this->radius);
    Vector2 recHalfExtent = Vector2({ rec.x / 2.0f, rec.y / 2.0f });
    Vector2 recCenter = Vector2({ rec.x + recHalfExtent.x, rec.y + recHalfExtent.y });
    Vector2 difference = Vector2Subtract(center, recCenter); 
    Vector2 clamped = Vector2Clamp(difference, Vector2Negate(recHalfExtent), recHalfExtent);

    Vector2 closest = Vector2Add(recCenter, clamped);
    difference = Vector2Subtract(closest, center);
    bool collide = Vector2Length(difference) < this->radius;
    return Collision {collide, clamped};
}
