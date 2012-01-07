#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"

void Game::init()
{      
  this->playerONE.init(false);
  this->playerTWO.init(true);      
  this->gameRunning = true;
}

void Game::update()
{
  if(this->gameRunning)
  {
    this->playerONE.update();
    this->playerTWO.update();
    this->b.update();        
  }
}

void Game::render()
{
  if(this->gameRunning)
  {
    this->playerONE.render();
    this->playerTWO.render();
    this->b.render();
  }
}

void Game::ballPassed(boolean side)
{
    
}

void Game::gameOver()
{
  LedSign::Clear();
}
