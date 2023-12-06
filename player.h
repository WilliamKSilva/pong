#include "raylib.h"

class Player {
public:
  Player(int width, int height, int posX, int posY, Color color);
  Rectangle shape;
  Color color;
  void Render();
};
