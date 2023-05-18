#pragma once
#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"

class Man{
    SDL_Rect srcRect, moverRect;
    friend class RunningMan;
public:
    void draw();        //draw function declared here
    Man(bool cflag);                //default constructor
    bool check;             //check used in RunningMan for jump checking
    void moving(bool cf);          //moving function 
    void jump(bool cfjump);            //jump function
    int i;                  // for horizontal animation 
    int frame = 0;          // for animation while jumping 
    ~Man();                 // destructor
};
