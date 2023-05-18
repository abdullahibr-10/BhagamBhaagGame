#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class coins_a {
    friend class RunningMan;               //made friend class so that private data can be used
    SDL_Rect srcRect, moverRect;
    public:
    void draw();    //draw declared here
    void move();    //move declared here
    coins_a();      //default constructor made
    ~coins_a();     //the destructor 
};