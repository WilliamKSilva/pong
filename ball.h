#include "raylib.h"

class Ball
{
  public:
    Ball(int x, int y, float radius, Color color);
    Vector2 *position;
    float radius;
    Color color;
    void Render();
};
