#include "Screen.h"
#include "DrawHelper.h"

Screen::Screen()
{
  resetScreen();
}

void Screen::resetScreen()
{
  for(int x = 0; x < 14; x++)
  {
    for(int y = 0; y < 9; y++)
    {
      data[x][y] = false;
    }  
  }  
}

void Screen::playScreen(ScreenType type)
{
  resetScreen();
  switch(type)
  {
    case WELCOME:
      loadWelcomeScreen();
  }
  play(10);  
}

void Screen::loadWelcomeScreen()
{
  //P
  data[1][5] = true;
  data[1][4] = true;
  data[1][3] = true;
  data[1][2] = true;
  data[1][1] = true;
  data[2][1] = true;
  data[3][1] = true;
  data[3][2] = true;
  data[3][3] = true;
  data[2][3] = true;
  
  //o
  data[3][7] = true;
  data[3][6] = true;  
  data[3][5] = true;
  data[4][5] = true;  
  data[5][5] = true;
  data[5][6] = true;
  data[5][7] = true;
  data[4][7] = true;
  
  //n
  data[7][4] = true;
  data[7][3] = true;  
  data[7][2] = true;
  data[8][2] = true;  
  data[9][2] = true;
  data[9][3] = true;
  data[9][4] = true;
  
  //g
  data[12][6] = true;
  data[11][6] = true;
  data[11][5] = true;  
  data[11][4] = true;
  data[12][4] = true;  
  data[13][4] = true;
  data[13][5] = true;
  data[13][6] = true;
  data[13][7] = true;
  data[13][8] = true;
  data[12][8] = true;  
}

void Screen::playScoreScreen(int score1,int score2)
{
  DrawHelper::drawNumber(score1,1,1);
  DrawHelper::drawLine(6,0,6,8);
  DrawHelper::drawLine(7,0,7,8);
  DrawHelper::drawNumber(score2, 9,1);
  delay(5000);  
}

void Screen::play(int del)
{
   for(int x = 0;x < 14; x++)
   {
     for(int y = 0; y < 9; y++)
     {
        LedSign::Set(x,y,data[x][y]);
        delay(del);
     }  
   }
}
