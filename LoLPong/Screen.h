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
  private:
    void loadWelcomeScreen();   
};
