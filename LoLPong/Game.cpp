#include "cppfix.h"
#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"
#include "Ball.h"

void Game::init()
{
  screen.playWelcomeScreen();
  this->playerONE = new Player();
  this->playerTWO = new Player();
  this->playerONE->init(LEFT_PLAYER);
  this->playerTWO->init(RIGHT_PLAYER);
  
  this->b = new Ball(*this);

  this->gameSpeed = 100;
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
    this->playerONE->score++;  
  }
  else
  {    
    this->playerTWO->score++;
  }  
  this->b->reset();
  LedSign::Clear();
  screen.playScoreScreen(playerONE->score,playerTWO->score);
}

void Game::gameOver()
{
  LedSign::Clear();
}
