#include "Charliplexing.h"
#include "WProgram.h"
#include "Game.h"

Game game;

void setup()
{
  LedSign::Init();
  game.init();
}

void loop()
{
  LedSign::Clear();
  game.update();
  game.render();
  delay(1000);
}


