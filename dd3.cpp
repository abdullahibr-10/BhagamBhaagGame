#include "dd3.hpp"
#include <iostream>

Drug3::Drug3(){
    // src coorinates using spritecow.com
    moverRect = {980,500, 80, 50};
     // setting x and y values
    srcRect = {22, 12, 23, 36};
}

void Drug3::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::DRUG3, &srcRect, &moverRect);  //draws the object
    if (frame == 0){srcRect = {70, 13, 24, 35};}       //the code below is how the state chnages
    else if (frame==1){srcRect = {117, 14, 24, 34};}
    else if (frame==2){srcRect = {162, 14, 27, 34};}
    else if (frame==3){srcRect = {211, 13, 26, 35};}
    else if (frame==4){srcRect = {261, 12, 24, 36};}
    frame++;                 //so that the frame/animation changes
    if (frame == 5){frame = 0;}
}

void Drug3::move(){
    moverRect.x -= 15;         //Drug1 moves 15 unit to the left.
}

Drug3 :: ~Drug3(){          //virtual destructor made here;
     
}