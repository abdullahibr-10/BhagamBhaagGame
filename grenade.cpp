#include "Grenade.hpp"
#include <iostream>

Grenade::Grenade(){
    // setting the values randomly
    moverRect = {(200 + rand() % 780),0, 70, 70};
    // src coorinates found using spritecow.com
    srcRect = {0, 0, 512, 512};
    objType = rand() % 2;           //Randomly assigning, to choose movement in draw
}

void Grenade::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::bomb, &srcRect, &moverRect);  //draws the object
}

void Grenade::move(){
    if(objType==0){
        moverRect.x += 15;              //Grenade moves right by 15 units
        moverRect.y += 20;              //Grenade moves down by 20 units
    }
    else if(objType==1){
        moverRect.x -= 15;
        moverRect.y += 20;
    }
    else if(objType==2){
        moverRect.y += 20;
    }
}

Grenade :: ~Grenade(){        // virtual destructor called
}