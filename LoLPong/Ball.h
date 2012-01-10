#pragma once

class Game;
class Ball
{
  public:
    int posX;
    int posY;
    int dirX;
    int dirY;
    int ballDelay; //how many game ticks till update
    Game* game;
    
    Ball(Game &g);
    void reset(void);
    void update(void);
    void render(void);    
  private:
    int tick; 
    void checkCollision(void);
    void increaseSpeed(void);
    int getRandomDirection(void);
};
