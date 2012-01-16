#include "Screen.h"
#include "DrawHelper.h"

Screen::Screen()
{
}

void Screen::playWelcomeScreen()
{
  delay(1000);
  //P
  LedSign::Set(1,5, true);
  LedSign::Set(1,4, true);
  LedSign::Set(1,3, true);
  LedSign::Set(1,2, true);
  LedSign::Set(1,1, true);
  LedSign::Set(2,1, true);
  LedSign::Set(3,1, true);
  LedSign::Set(3,2, true);
  LedSign::Set(3,3, true);
  LedSign::Set(2,3, true);

  delay(1000);  
  //o
  LedSign::Set(3,7, true);
  LedSign::Set(3,6, true);  
  LedSign::Set(3,5, true);
  LedSign::Set(4,5, true);  
  LedSign::Set(5,5, true);
  LedSign::Set(5,6, true);
  LedSign::Set(5,7, true);
  LedSign::Set(4,7, true);
  
  delay(1000);
  //n
  LedSign::Set(7,4, true);
  LedSign::Set(7,3, true);  
  LedSign::Set(7,2, true);
  LedSign::Set(8,2, true);  
  LedSign::Set(9,2, true);
  LedSign::Set(9,3, true);
  LedSign::Set(9,4, true);
  
  delay(1000);
  //g
  LedSign::Set(12,6, true);
  LedSign::Set(11,6, true);
  LedSign::Set(11,5, true);  
  LedSign::Set(11,4, true);
  LedSign::Set(12,4, true);  
  LedSign::Set(13,4, true);
  LedSign::Set(13,5, true);
  LedSign::Set(13,6, true);
  LedSign::Set(13,7, true);
  LedSign::Set(13,8, true);
  LedSign::Set(12,8, true);
  
  delay(5000);
}

void Screen::playScoreScreen(int score1,int score2)
{
  if((score1 == 9) || (score2 == 9))
  {
    for(int i = 0; i < 10; i++)
    {
      drawScores(score1,score2);
      LedSign::Clear();
      delay(500);
    }
  }
  else
  {
    drawScores(score1,score2);
  }
  delay(3000);  
}

void Screen::drawScores(int score1, int score2)
{
  DrawHelper::drawNumber(score1,1,1);
  DrawHelper::drawLine(6,0,6,9);
  DrawHelper::drawLine(7,0,7,9);
  DrawHelper::drawNumber(score2, 9,1);  
}
