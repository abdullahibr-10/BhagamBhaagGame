#include "dd2.hpp"
#include <iostream>

Drug2::Drug2(){
    // src coorinates using spritecow.com
    moverRect = {980,500, 80, 50};
     // setting x and y values
    srcRect = {24, 7, 91, 41};
}

void Drug2::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::DRUG2, &srcRect, &moverRect);  //draws the object
    if (frame == 0){srcRect = {70, 7, 23, 41};}       //the code below is how the state chnages
    else if (frame==1){srcRect = {117, 8, 26, 40};}
    else if (frame==2){srcRect = {166, 7, 24, 41};}
    else if (frame==3){srcRect = {217, 7, 18, 41};}
    else if (frame==4){srcRect = {263, 8, 18, 40};}
    frame++;                 //so that the frame/animation changes
    if (frame == 5){frame = 0;}
}

void Drug2::move(){
    moverRect.x -= 15;         //Drug1 moves 15 unit to the left.
}

Drug2 :: ~Drug2(){          //virtual destructor made here;
     
}