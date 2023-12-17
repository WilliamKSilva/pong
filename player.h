#include "raylib.h"

class Player {
public:
  Player(int width, int height, int posX, int posY, Color color);
  Vector2 position;
  Vector2 speed;
  int width;
  int height;
  int score;
  Color color;
  void Render();
  void HandleInput();
  void UpdateScore();
};
