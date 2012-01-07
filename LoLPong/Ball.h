class Ball
{
  public:
    int posX, posY;
    int dirX,dirY;
    Ball();
    void init();
    void update();
    void render();
    
  private: 
    void checkCollision();
};
