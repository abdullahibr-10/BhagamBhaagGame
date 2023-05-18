#include "police man.hpp"
#include <iostream>

PoliceMan::PoliceMan(){
    // src coordinates from file, they have been found using spritecow.com
    moverRect = {25, 500, 50, 50};
    // setting the values
    srcRect = {67, 47, 50, 50};
}

void PoliceMan::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::police, &srcRect, &moverRect);  //draws the object
    //putting checks for the animation                                          //srcRect values taken from spritecow
    if (frame == 0){srcRect = {67, 47, 62, 59};}
    else if (frame==1){srcRect = {150,43,46,63};}
    else if (frame==2){srcRect = {220,48,54,58};}
    frame++;         //so that the frame/animation changes
    if (frame == 3){frame = 0;}
}

void PoliceMan::move(){
    moverRect.x += 7;       //objects move to the left by 7 units 
}

PoliceMan :: ~PoliceMan(){            //destructor made to fully erase the existence of the object
}