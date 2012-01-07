#pragma once

#include "Player.h"
#define LEFT_PLAYER false
#define RIGHT_PLAYER true

class Ball;

class Game
{
  public:
    Player* playerONE;
    Player* playerTWO;
    Ball* b;    
    boolean gameRunning;
    int gameSpeed;
    
    void init(void);
    void update(void);
    void render(void);
    void ballPassed(boolean side);
    void gameOver(void);
};
