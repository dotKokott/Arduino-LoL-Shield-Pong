#include "Ball.h"
#include "Charliplexing.h"
#include "WProgram.h"

Ball::Ball()
{
      this->posX = 6;
      this->posY = 2;
      this->dirX = 1; 
      this->dirY = -1; 
}

void Ball::update()
{
    this->checkCollision();
    this->posX += this->dirX;
    this->posY += this->dirY; 
}

void Ball::render()
{
  LedSign::Set(this->posX,this->posY,true);
}

void Ball::checkCollision()
{      
  int expectedX = this->posX + this->dirX;
  int expectedY = this->posY + this->dirY;
  
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
    //g.gameOver();
    this->dirY = this->dirY * -1;
  }       
}
