#include "man.hpp"
#include <iostream>
//Man implementation will go here.

Man::Man(bool cflag){
    // src coorinates found using spritecow.com

    if (cflag == 0)
    {
        srcRect = {63, 619, 151, 166};
    }
    else if (cflag == 1)
    {
        srcRect = {140, 256, 72, 152};
    }

    
    i = 0 ;
     // setting the values
    moverRect = {30,500, 50, 50};
}


void Man::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);  //draws the object
}


void Man::jump(bool cfjump){      //this function is for the jump 
    //there is a change in the animations 
    //there is movement in the Y direction as well

    if (cfjump == 0)
    {
        if (frame == 0){srcRect = {0,218,85,154};}
        else if (frame==1){srcRect = {103,190,86,154};}
        else if (frame==2){srcRect = {210,159,86,154};}
        else if (frame==3){srcRect = {300,178,88,149};}
        else if (frame==4){srcRect = {391,215,88,150} ;}
        frame++; 
    }

    else if (cfjump == 1)
    {
        if (frame == 0){srcRect = {344,507,88,156};}
        else if (frame==1){srcRect = {472,456,84,155};}
        else if (frame==2){srcRect = {588,519,104,148};}
        else if (frame==3){srcRect = {712,547,108,140};}
        else if (frame==4){srcRect = {188,547,104,144} ;}
        frame++; 
    }


    

    if (moverRect.x >= 950){     //restricting the man to the size of the screen 
        moverRect.x = 50;}

    moverRect.x += 20;     //for movement in right direction

    if (frame <3){              //to bring the player down
    moverRect.y -= 90;}
    else
    {moverRect.y += 60;}
    if (frame==5){frame=0; check =false;}   //making the i again 0 -> making the srcRect again
}

void Man::moving(bool cf){
    //this function is called only for the horizontal movement 
    //the change in 'i' here is for the animation

    if (cf == 0)
    {
        if (i == 0){srcRect = {207,2,95,141};}
        else if (i==1){srcRect = {326, 2, 80, 141};}
        else if (i==2){srcRect = {434,0,72,143};}
        else if (i==3){srcRect = {535,2,86,141};}
        else if (i==4){srcRect = {0,6,66,137} ;}
        else if (i==5){srcRect = {95,0,84,143};}
        i++; 
    }

    else if (cf == 1)
    {
        if (i == 0){srcRect = {252,260,80,152};}
        else if (i==1){srcRect = {376, 256, 76, 156};}
        else if (i==2){srcRect = {628,256,76,152};}
        else if (i==3){srcRect = {756,260,88,152};}
        else if (i==4){srcRect = {900,256,72,152} ;}
        else if (i==5){srcRect = {140, 256, 72, 152};}
        i++; 
    }

    if (moverRect.x >= 950){     //restricting the man to the size of the screen 
        moverRect.x = 50;}

    if (i==6){i = 0;} 
}

Man :: ~Man(){     //destructor made to remove the instance
}

