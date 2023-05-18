#include "coins_a.hpp"
#include <iostream>
//Bottom path coins implementation will go here.

coins_a::coins_a(){
    // src coorinates found using spritecow
    moverRect = {980,500, 50, 50};
     // setting the values
    srcRect = {120, 117, 372, 357};
}

void coins_a::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::collectiblecoin, &srcRect, &moverRect);  //draws the object. No animation here
}

void coins_a::move(){
    moverRect.x -= 20;            //objects move to the left by 20 units 
}

coins_a :: ~coins_a(){        //destructor made to fully erase the existence of the object
}
