#include "Charliplexing.h"
#include "WProgram.h"

#include "Game.h"
#include "Ball.h"

Ball::Ball(Game *g)
{
      this->reset();
      this->game = g;
}

void Ball::reset()
{
  this->posX = 6;
  this->posY = 2;
  this->dirY = -1; //random would be cool 
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
    this->game->ballPassed(LEFT_PLAYER);
  }
  
  if(expectedX > 13)
  {
    this->game->ballPassed(RIGHT_PLAYER);
  }

  //PanelCollisionDetection
  
  if((expectedY) < 0 || (expectedY) > 8)
  {    
    this->dirY = this->dirY * -1;
  }       
}
