#include "raylib.h"

struct Collision {
    bool collide;
    Vector2 point;
};

class Ball
{
  public:
    Ball(int x, int y, float radius, Color color);
    Vector2 position;
    float radius;
    Color color;
    void Render();
    void BounceCenter();
    Collision DetectCollision(Rectangle rec);
};
