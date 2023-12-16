#include "raylib.h"

struct CollisionObject {
    bool collide;
    bool movingLeft;
    Vector2 point;
};

struct CollisionTopAndBottom {
    Vector2 point;
    bool movingLeft;
    bool top;
    bool collide;
};

class Ball
{
  public:
    Ball(int x, int y, float radius, Color color);
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
    CollisionObject *objectCollision; 
    CollisionTopAndBottom *topBottomCollision; 
    void Render();
    void Move();
    CollisionObject ObjectCollision(Rectangle rec);
    CollisionTopAndBottom TopAndBottomCollision();
};
