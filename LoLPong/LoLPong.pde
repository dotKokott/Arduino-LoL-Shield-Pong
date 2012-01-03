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
      //Read from potentiometer
      // x = (1023 / 9) * pinRead?
    }
    
    void render() //called after update, draws panel on the shield
    {
        for(int i = 0; i < panelSize; i++)
        {
          LedSign::Set(posX,posY + i, true);
        }
    }      
};

class Game;

class Ball
{
  public:
    int posX, posY;
    int dirX,dirY;
    int ballSpeed;
    Game* g;
    Ball()
    {
      posX = 6;
      posY = 2;
      dirX = 1; 
      dirY = -1;
    }
   
    void init(Game& game)
    {
       g = &game;
    } 

    void update()
    {
      checkCollision();
      posX += dirX;
      posY += dirY;
      
    }       

    void render()
    {
      LedSign::Set(posX,posY,true);
    }
  private:
    void checkCollision()
    {      
      int expectedX = posX + dirX;
      int expectedY = posY + dirY;
      
      if(expectedX <= 0)
      {
        //Player left point
      }
      
      if(expectedX > 13)
      {
        //Player right point
      }

      //PanelCollisionDetection
      
      if((expectedY) < 0 || (expectedY) > 8)
      {
        g.gameOver();
        this->dirY = this->dirY * -1;
      }       
    }  
};

class Game
{  
  public:
    Player playerONE;
    Player playerTWO;
    Ball b;
    
    boolean gameRunning;
    void init()
    {      
      playerONE.init(false);
      playerTWO.init(true);      
      gameRunning = true;
    }

    void update()
    {
      if(gameRunning)
      {
        playerONE.update();
        playerTWO.update();
        b.update();        
      }
    }
    
    void render()
    {
      if(gameRunning)
      {
        playerONE.render();
        playerTWO.render();
        b.render();
      }
    }
    
    void ballPassed(boolean side)
    {
        
    }
    
    void gameOver()
    {
      LedSign::Clear();
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


