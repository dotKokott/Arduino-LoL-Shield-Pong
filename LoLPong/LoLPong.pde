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
  Serial.begin(19200);
  randomSeed(analogRead(0));
  LedSign::Init();
  game.init();
}

void loop()
{
  LedSign::Clear();
  game.update();
  game.render();
  delay(game.gameSpeed);
}
