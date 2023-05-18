#include<SDL.h>
#include "drawing.hpp"

class explosion{
    friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    void draw();           //declaration of draw 
    explosion();           //default constructor
    explosion(int, int);   //Overloaded constructor
    ~explosion();          //deconstructor called
    int value = 0;         //Counter/timer variable
};