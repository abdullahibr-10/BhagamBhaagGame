#include<SDL.h>
#pragma once
class Drawing{
    public:
        //The window renderer
    static SDL_Renderer* gRenderer;
    //global reference to png image sheets
    static SDL_Texture* assets;         //Man Image
    static SDL_Texture* police;         //Police Image
    static SDL_Texture* collectiblecoin;             //Coin Image
    static SDL_Texture* life;           //Life Image
    static SDL_Texture* bomb;         //Meteor Image
    static SDL_Texture* exp;            //Explosive Effect Image
    static SDL_Texture* Ride_back;      //car Image
    static SDL_Texture* DRUG1;
    static SDL_Texture* DRUG2;
    static SDL_Texture* DRUG3;          //Crowd Image
    static SDL_Texture* HealthPickup;  //Health pickup Image
};