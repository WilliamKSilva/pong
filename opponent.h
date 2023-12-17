#include "raylib.h"

class Opponent 
{
  public:
    Opponent(Vector2 position, Vector2 speed, int width, int height, Color color);
    Vector2 position;  
    Vector2 speed;
    int width;
    int height;
    Color color;
    void Render();
    void Move(Vector2 ballPosition);
};
