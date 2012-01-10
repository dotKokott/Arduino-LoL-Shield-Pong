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
#include "NumberRenderer.h"

Game game;

void setup()
{
  randomSeed(analogRead(0));
  LedSign::Init();
  game.init();
  NumberRenderer::drawNumber(0,0,0);
  delay(10000000);
}

void loop()
{
  game.update();
  LedSign::Clear();
  game.render();
  delay(game.gameSpeed);
}
