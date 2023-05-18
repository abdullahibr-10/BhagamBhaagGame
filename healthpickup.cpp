#include "healthpickup.hpp"
#include <iostream>
//Bottom path coins implementation will go here.

healthpickup::healthpickup(){
    // src coorinates found using spritecow
    moverRect = {980,500, 50, 50};
     // setting the values
    srcRect = {0, 0, 30, 50};
}

void healthpickup::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::HealthPickup, &srcRect, &moverRect);  //draws the object. No animation here
}

void healthpickup::move(){
    moverRect.x -= 20;            //objects move to the left by 20 units 
}

healthpickup :: ~healthpickup(){        //destructor made to fully erase the existence of the object
}
