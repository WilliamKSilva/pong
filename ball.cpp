#include "ball.h"
#include <raylib.h>
#include <iostream>

Ball::Ball(int x, int y, float radius, Color color)
{
    position = new Vector2();
    position->x = x;
    position->y = y;
    this->radius = radius;
    this->color = color;
}

void Ball::Render()
{
    std::cout << position->x << std::endl;
    std::cout << position->y << std::endl;
    DrawCircleV(*position, radius, color);
}
