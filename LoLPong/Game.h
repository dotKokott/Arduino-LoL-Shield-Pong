#include "Ball.h"
#include "Player.h"

class Game
{
  public:
    Player playerONE;
    Player playerTWO;
    Ball b;
    boolean gameRunning;
    void init();
    void update();
    void render();
    void ballPassed(boolean side);
    void gameOver();
};
