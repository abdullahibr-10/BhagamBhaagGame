#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class PoliceMan : public Unit{
    friend class RunningMan;               //made friend class so that private data can be used
    public:
    int frame = 0 ;         //for animation
    void draw();            //declaration of draw 
    void move();            //declaration of move
    PoliceMan();           //default constructor
    ~PoliceMan();          //deconstructor called
};