#include "cppfix.h"
#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"
#include "Ball.h"

void Game::init()
{
  //this->playerONE = new Player();
  //this->playerTWO = new Player();
  this->playerONE->init(false);
  this->playerTWO->init(true);
  
  this->b = new Ball(*this);

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
