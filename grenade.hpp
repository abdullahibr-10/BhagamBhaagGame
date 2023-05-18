#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
class Grenade : public Unit{
    friend class RunningMan;               //made friend class so that private data can be used
    public:
    int objType;        //To store the type of movement the meteor will have
    void draw();        //draw function declared
    void move();        //move function declared
    Grenade();           //default constructor 
    ~Grenade();          //destructor 
};