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
    Vector2 speed;
    float radius;
    Color color;
    Collision *lastCollision; 
    void Render();
    void Move();
    Collision DetectCollision(Rectangle rec);
};
