#include "carobstacle.hpp"
#include <iostream>

carobstacle::carobstacle(){
    // src coorinates using spritecow.com
    moverRect = {980,500, 80, 50};
     // setting x and y values
    srcRect = {19, 69, 80, 31};
}

void carobstacle::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::Ride_back, &srcRect, &moverRect);  //draws the object
    if (frame == 0){srcRect = {119, 69, 80, 31};}       //the code below is how the state chnages
    else if (frame==1){srcRect = {119, 69, 80, 31};}
    else if (frame==2){srcRect = {219, 69, 80, 31};}
    else if (frame==3){srcRect = {319, 69, 80, 31};}
    else if (frame==4){srcRect = {419, 69, 80, 31};}
    else if (frame==5){srcRect = {519, 69, 80, 31};}
    else if (frame==6){srcRect = {619, 69, 80, 31};}
    else if (frame==7){srcRect = {719, 69, 81, 31};}
    frame++;                 //so that the frame/animation changes
    if (frame == 8){frame = 0;}
}

void carobstacle::move(){
    moverRect.x -= 15;         //carobstacle moves 15 unit to the left.
}

carobstacle :: ~carobstacle(){          //virtual destructor made here;
     
}