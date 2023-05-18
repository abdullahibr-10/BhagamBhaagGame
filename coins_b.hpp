#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class coins_b{
    friend class RunningMan;               //made friend class so that private data can be used
    SDL_Rect srcRect, moverRect;
    public:
    int counts = 0 ;         
    void draw();    //draw declared here
    void operator++();          //opeartor overoading done
    coins_b();      //default constructor made
    ~coins_b();     //the destructor 
};