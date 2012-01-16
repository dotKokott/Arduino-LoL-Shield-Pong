#include "cppfix.h"
#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"
#include "Ball.h"

Game::Game()
{
  this->playerONE = new Player(LEFT_PLAYER);
  this->playerTWO = new Player(RIGHT_PLAYER);
  this->b = new Ball(*this);
  
  init();
}

void Game::init()
{
  screen.playWelcomeScreen();
  
  this->playerONE->init();
  this->playerTWO->init(); 
  this->b->init();
  
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
  LedSign::Clear();
  this->playerONE->render();
  this->playerTWO->render();
  this->b->render();
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
  
  this->b->init();
  
  LedSign::Clear();
  screen.playScoreScreen(playerONE->score,playerTWO->score);
  if((playerONE->score == 9) || (playerTWO->score == 9))
  {
    init();
  }  
}
