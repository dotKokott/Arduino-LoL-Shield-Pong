#include "Charliplexing.h"
#include "WProgram.h"
#include "Player.h"
    
Player::Player()
{
  this->score = 0;
  this->panelSize = 13;
  this->posY = 0;
}

void Player::init(boolean playerSide)
{
  this->side = playerSide;
  if(playerSide)
  {
    this->posX = 13;
  }
  else
  {
    this->posX = 0;
  }
}

void Player::update() //called each loop, checks input, updates position etc.
{
  //Read from potentiometer
  // x = (1023 / 9) * pinRead?
}

void Player::render() //called after update, draws panel on the shield
{
    for(int i = 0; i < this->panelSize; i++)
    {
      LedSign::Set(this->posX,this->posY + i, true);
    }
}
