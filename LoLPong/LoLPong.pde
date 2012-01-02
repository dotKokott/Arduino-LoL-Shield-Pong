#include "Charliplexing.h"
#include "WProgram.h"

class Player
{
  public:
    boolean side;
    boolean panelSize;
    int posX,posY;
    int score;    
    
    Player()
    {
      score = 0;
      panelSize = 13;
      posY = 0;
    }
    
    void init(boolean playerSide)
    {
      side = playerSide;
      if(playerSide)
      {
        posX = 13;
      }
      else
      {
        posX = 0;
      }
    }
    
    void update() //called each loop, checks input, updates position etc.
    {
      
    }
    
    void render() //called after update, draws panel on the shield
    {
        for(int i = 0; i < panelSize; i++)
        {
          LedSign::Set(posX,posY + i, true);
        }
    }      
};

class Ball
{
  public:
    int posX, posY;
    int dirX,dirY;
    int ballSpeed;
   
    Ball()
    {
      posX = 6;
      posY = 2;
      dirX = dirY = 1;
      ballSpeed = 1;
    } 

    void update()
    {
      checkCollision();
      posX += ballSpeed * dirX;
      posY += ballSpeed * dirY;
    }

    void render()
    {
      LedSign::Set(posX,posY,true);
    }
  private:
    void checkCollision()
    {
      if(posX += ballSpeed * dirX <= 0
    }  
};

class Game
{  
  public:
    Player playerONE;
    Player playerTWO;
    Ball b;
    void init()
    {
      playerONE.init(false);
      playerTWO.init(true);
    }

    void update()
    {
      playerONE.update();
      playerTWO.update();
      b.update();
    }
    
    void render()
    {
      playerONE.render();
      playerTWO.render();
      b.render();
    }	
};

Game game;

void setup()
{
  LedSign::Init();
  game.init();
}

void loop()
{
  LedSign::Clear();
  game.update();
  game.render();
  delay(1000);
}


