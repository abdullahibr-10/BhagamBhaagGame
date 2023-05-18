#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class Drug2 : public Unit{
    friend class RunningMan;               //made friend class so that private data can be used
    //SDL_Rect srcRect, moverRect;
    public:
    int frame = 0 ;       //for animation
    void draw();        //declaration of draw 
    void move();        //declaration of move
    Drug2();           //default constructor
    ~Drug2();          //deconstructor called
};
