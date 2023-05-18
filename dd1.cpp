#include "dd1.hpp"
#include <iostream>

Drug1::Drug1(){
    // src coorinates using spritecow.com
    moverRect = {980,500, 80, 50};
     // setting x and y values
    srcRect = {23, 15, 21, 33};
}

void Drug1::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::DRUG1, &srcRect, &moverRect);  //draws the object
    if (frame == 0){srcRect = {70, 15, 23, 33};}       //the code below is how the state chnages
    else if (frame==1){srcRect = {117, 16, 26, 32};}
    else if (frame==2){srcRect = {166, 15, 24, 33};}
    else if (frame==3){srcRect = {215, 15, 21, 33};}
    else if (frame==4){srcRect = {264, 16, 20, 32};}
    frame++;                 //so that the frame/animation changes
    if (frame == 5){frame = 0;}
}

void Drug1::move(){
    moverRect.x -= 15;         //Drug1 moves 15 unit to the left.
}

Drug1 :: ~Drug1(){          //virtual destructor made here;
     
}