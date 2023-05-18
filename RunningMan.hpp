#include<SDL.h>
#include "man.hpp"
#include "police man.hpp"
#include "lives.hpp"
#include "coins_a.hpp"
#include "coins_b.hpp"
#include "Unit.hpp"
#include "Grenade.hpp"
#include "explosion.hpp"
#include "carobstacle.hpp"
#include "healthpickup.hpp"
#include "dd1.hpp"
#include "dd2.hpp"
#include "dd3.hpp"
#include<vector>
#include<list>
using namespace std;

class RunningMan{
    vector<Man*> man;                       //for storing the objects of the player
    vector<lives> living;                   //for storing lives
    vector<explosion> explosive;            //for storing the explosion when hitting policeman
    vector<coins_b> Coins;                  //for storing coins collected
    vector<coins_a*> Coin_Bottom;               //Vector to store the bottom/moving coins
    vector<healthpickup*> health;           //for storing the health objects
    list <Unit*> things;                   //for storing the policeman and grenades

    public:
    bool Coin_Check = false;                //if coin is collected or not
    bool lost_check = false;                //if all lives finish (game lost)
    bool win_check = false;                 //if all coins collected (game won)
    int tick = 0 ;                          //for some delay
    bool life_check = false;                //if live lost by collision with police
    bool life_upgrade = false;
    bool jumps = false ;                    //for checking if user pressed up button (for jumping)
    bool left = false ;                     //for checking if user pressed left button (for moving left)
    bool right = false ;                    //for checking if user pressed right button (for moving right)
    int counter=0;                          //counting how many objects created
    void drawObjects(bool chardraw);                     //for drawing all objects
    void createObject(bool charflag);                    //for creating objects and pushing them to the vector list
    void emptying();                        //for emptying objects from the list and destroying them

    ~RunningMan();                          //Destructor
};
