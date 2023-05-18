#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "man.hpp"
#include <iostream>
using namespace std;

class Unit{             //defining a class named unit that will be inherited by carobstacle, grenade, police classes
    protected:
        SDL_Rect srcRect, moverRect;        //These attributes will be inherited by the child classes. This would contain initial srcRect, moverRect values.
    public:
        Unit();                         //constructor
        virtual void draw() = 0;       //pure virtual draw function as it is unique to each class
        virtual void move() = 0;       //pure virtual move function as it is unique to each class
        friend class RunningMan;       //Friend class to access the private attributes of the class 
        virtual ~Unit();               //virtual destructor called 
};