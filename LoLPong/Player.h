#pragma once

class Player
{
  public:
    boolean side;
    boolean panelSize;
    int posX,posY;
    int score;
    Player();
    
    void init(boolean playerSide);
    void update();
    void render();    
};
