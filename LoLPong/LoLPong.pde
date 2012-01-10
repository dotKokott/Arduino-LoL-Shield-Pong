/* 
  Created by Christian Kokott on 06.01.2012 (01/06/2012)
  Version 0.1  
*/

#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"

Game game;

void setup()
{
  randomSeed(analogRead(0));
  LedSign::Init();
  game.init();
}

void loop()
{
  game.update();
  LedSign::Clear();
  game.render();
  delay(game.gameSpeed);
}
