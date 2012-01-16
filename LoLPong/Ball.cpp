#include "Charliplexing.h"
#include "WProgram.h"

#include "Game.h"
#include "Ball.h"

Ball::Ball(Game &g)
{
  this->game = &g;
  this->init();
}

int Ball::getRandomDirection()
{
  long rand = random(1,3);
  if(rand == 1) return rand;
  if(rand == 2) return -1;
}

void Ball::init()
{
  this->tick = 0;
  this->ballDelay = 5;
  this->posX = 6;
  this->posY = 4;
  this->dirY = getRandomDirection(); 
  this->dirX = getRandomDirection(); 
}

void Ball::update()
{
    if(tick==ballDelay)
    {      
      this->checkCollision();
      this->posX += this->dirX;
      this->posY += this->dirY;
      tick = 0;
    }
    else
    {
      tick++;
    }    
}

void Ball::render()
{
  LedSign::Set(this->posX,this->posY,true);
}

void Ball::increaseSpeed()
{
  if(ballDelay>1) ballDelay--; 
}

void Ball::checkCollision()
{ 
     //Top-Bottom wall collision
  if((posY + dirY) < 0 || (posY + dirY) > 8)
  {    
    this->dirY = this->dirY * -1;
  }   
  int expectedX = this->posX + this->dirX;
  int expectedY = this->posY + this->dirY;

  if(expectedX < 0)
  {
    this->game->ballPassed(LEFT_PLAYER);
  }
  
  if(expectedX > 13)
  {
    this->game->ballPassed(RIGHT_PLAYER);
  }

  //PanelCollisionDetection
  if(dirX == 1) //floats right
  {
    if((expectedX == 13) && (expectedY >= game->playerTWO->posY && expectedY <= game->playerTWO->posY + game->playerTWO->panelSize -1))
    {
      dirX *= -1;
      increaseSpeed();
    }
  }
  
  if(dirX == -1) //floats left
  {
    if((expectedX == 0) && (expectedY >= game->playerONE->posY && expectedY <= game->playerONE->posY + game->playerONE->panelSize -1))
    {
      dirX *= -1;
      increaseSpeed();  
    }
  }
}
