#pragma once

class Player
{
  public:
    Player(boolean playerSide);
    boolean side;
    int panelSize;
    int posX;
    int posY;
    int score;
    Player();
    
    void init(void);
    void update(void);
    void render(void);    
};
