#include "Charliplexing.h"
#include "WProgram.h"

#define SetLED(x,y) (LedSign::Set(x,y,true))

class NumberRenderer
{
  public:
    static void drawNumber(int number, int posX, int posY)
    {
      switch(number)
      {
        case 0:
          draw0(posX,posY);
          break;
        case 1:
          draw1(posX,posY);
          break;
        case 2:
          draw2(posX,posY);
          break;
        case 3:
          draw3(posX,posY);
          break;
        case 4:
          draw4(posX,posY);
          break;
        case 5:
          draw5(posX,posY);
          break;
        case 6:
          draw6(posX,posY);
          break;
        case 7:
          draw7(posX,posY);
          break;
        case 8:
          draw8(posX,posY);
          break;
        case 9:
          draw9(posX,posY);
          break;          
      }
    }
    static void drawLine(int startX, int startY, int endX, int endY)
    {
      int posX = startX;
      int posY = startY;
  
      do 
      {
        SetLED(posX, posY);
        if(posX != endX) posX++;
        if(posY != endY) posY++;
      }
      while ((posX != endX) || (posY != endY));
      
     }
    static void draw0(int posX, int posY)
    {       
       drawLine(posX, posY, posX, posY+6); //links vertikal
       drawLine(posX+3, posY, posX+3, posY+6); // rechts vertikal
       drawLine(posX, posY, posX+4, posY); // oben horizontal
       drawLine(posX, posY+6, posX+4, posY+6); // unten horizoontal
      
    }    
    
    static void draw1(int posX, int posY)
    {
      
    }
    
    static void draw2(int posX, int posY)
    {
      
    }
    
    static void draw3(int posX, int posY)
    {
      
    }    
    
    static void draw4(int posX, int posY)
    {
      
    }

    static void draw5(int posX, int posY)
    {
      
    }

    static void draw6(int posX, int posY)
    {
      
    }

    static void draw7(int posX, int posY)
    {
      
    }

    static void draw8(int posX, int posY)
    {
      
    }

    static void draw9(int posX, int posY)
    {
      
    }
};
