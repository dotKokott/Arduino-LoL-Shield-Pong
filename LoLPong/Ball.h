#pragma once
#include <stdlib.h>

class Game;
class Ball
{
  public:
    int posX;
    int posY;
    int dirX;
    int dirY;
    Game* game;
    
    Ball(Game &g);
    void reset(void);
    void update(void);
    void render(void);    
  private: 
    void checkCollision(void);
};
