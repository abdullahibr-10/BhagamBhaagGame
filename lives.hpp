#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class lives{
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;               //made friend class so that private data can be used
public:
    void draw();          //draw declared here
    lives();                //default construcot
    void operator--();         //operator overloading
    void operator++();         //operator overloading
    int l_left = 10;            //the amount of inintial light
    ~lives();
};