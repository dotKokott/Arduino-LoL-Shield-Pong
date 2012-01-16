#pragma once
#include "Charliplexing.h"
#include "WProgram.h"

class Screen
{
  public:
    Screen();
    void playScoreScreen(int score1, int score2);
    void playWelcomeScreen(void);    
  private:
    void drawScores(int score1, int score2);
};
