#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"
#include "Ball.h"

void Game::init()
{
  Player first;
  Player second;
  first.init(LEFT_PLAYER);
  second.init(RIGHT_PLAYER);
  
  this->playerONE = &first;
  this->playerTWO = &second;
  
  Ball ball(this);
  this->b = &ball; 

  this->gameSpeed = 1000;
  this->gameRunning = true;
}

void Game::update()
{
  if(this->gameRunning)
  {
    this->playerONE->update();
    this->playerTWO->update();
    this->b->update();        
  }
}

void Game::render()
{
  if(this->gameRunning)
  {
    this->playerONE->render();
    this->playerTWO->render();
    this->b->render();
  }
}

void Game::ballPassed(boolean side)
{
  if(side)
  {
    this->playerTWO->score++;
  }
  else
  {
    this->playerONE->score++;  
  }  
  this->b->reset();
}

void Game::gameOver()
{
  LedSign::Clear();
}
