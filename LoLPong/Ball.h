#pragma once

class Game;
class Ball
{
  public:
    int posX, posY;
    int dirX,dirY;
    Game* game;
    
    Ball(Game *g);
    void reset(void);
    void update(void);
    void render(void);    
  private: 
    void checkCollision(void);
};
