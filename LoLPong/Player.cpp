#include "Charliplexing.h"
#include "WProgram.h"
#include "Player.h"
    
Player::Player(boolean playerSide)
{
  this->side = playerSide;
  this->score = 0;
  this->panelSize = 3;
  this->posY = 0;
  this->posX = 0;  
}

void Player::init()
{
  this->score = 0;
  if(side)
  {
    this->posX = 13;
  }
  else
  {
    this->posX = 0;
  }
  this->posY = 3;
}

void Player::update() //called each loop, checks input, updates position etc.
{
  //Read from potentiometer
  int value = analogRead(2);
  posY = ((float)8 / (float)1023) * value;
}

void Player::render() //called after update, draws panel on the shield
{
  for(int i = 0; i < this->panelSize; i++)
  {
    LedSign::Set(this->posX,this->posY + i, true);
  }
}
