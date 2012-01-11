#pragma once
#include "Charliplexing.h"
#include "WProgram.h"

enum ScreenType
{
  WELCOME,
  SHOWSCORE,
  PLAYERWON  
};

class Screen
{
  public:
    boolean data[14][9];
    Screen();
    //~Screen();
    void resetScreen();
    void playScreen(ScreenType type);
    void play(int del);
    void playScoreScreen(int score1, int score2);
  private:
    void loadWelcomeScreen();
    
};
