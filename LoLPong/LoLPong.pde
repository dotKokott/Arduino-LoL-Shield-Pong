//**************************************************************//
//  Name    : Pong for Arduino                                  //
//  Author  : Christian Kokott twitter.com/chrixko              //
//  Date    : 10 January 2012                                   //
//  Version : 0.1                                               //
//  Notes   : Uses Charlieplexing library to light up           //
//          : a matrix of 126 LEDs in a 9x14 grid               //
//          : from Jimmie P Rodgers www.jimmieprodgers.com      //
//**************************************************************//

#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"

Game game;

void setup()
{
  randomSeed(analogRead(0));
  LedSign::Init();
  game.init(); //Initializes the game, sets the players on the right positions etc. and then starts the game
}

void loop()
{
  game.update(); //updates the game, checks player input and moves the ball
  game.render(); //renders the game, draws the players and the ball
  delay(game.gameSpeed);
}
