#pragma once
#include "Player.h"
#include "Screen.h"

#define LEFT_PLAYER false
#define RIGHT_PLAYER true

class Ball;

class Game
{
  public:
    Game();
    Screen screen;
    Player* playerONE;
    Player* playerTWO;
    Ball* b;    
    boolean gameRunning;
    int gameSpeed;
    
    void init(void);
    void reset(void);
    void update(void);
    void render(void);
    void ballPassed(boolean side);    
};
