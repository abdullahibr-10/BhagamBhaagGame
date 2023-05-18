#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class healthpickup {
    friend class RunningMan;               //made friend class so that private data can be used
    SDL_Rect srcRect, moverRect;
    public:
    void draw();    //draw declared here
    void move();    //move declared here
    healthpickup();      //default constructor made
    ~healthpickup();     //the destructor 
};