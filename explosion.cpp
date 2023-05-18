#include "explosion.hpp"
#include <iostream>

explosion::explosion(){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {433, 300, 50, 50};
     // setting the values
    //srcRect = {488, 300, 50, 50};
    srcRect = {10, 0, 236, 256};
}

explosion::explosion(int x, int y){
    // src coorinates from file, they have been found using spritecow.com
    moverRect = {x, y, 50, 50};
     // setting the values
    //srcRect = {488, 300, 50, 50};
    srcRect = {10, 0, 236, 256};
}

void explosion::draw(){         //this is the draw function
    SDL_RenderCopy(Drawing::gRenderer, Drawing::exp, &srcRect, &moverRect);  //draws the object
}

explosion :: ~explosion(){          //destructor called to fully erase the existence of the object    
}