#include <iostream>
#include "RunningMan.hpp"
#include "screenInfo.hpp"
#include "Unit.hpp"

using namespace std;

void RunningMan::drawObjects(bool chardraw)                                 //draws all the objects
{   
    int k,t = 0; 
    
    // draw explosive objects
    while (t < explosive.size()){  //iterating over the explosives vector to make the objects
        if (explosive[t].value < 20){  // check timer variable
            explosive[t].draw();  // call draw function
            explosive[t].value++;  // increment timer variable
        } else {
            explosive.erase(explosive.begin() + t);  // remove from vector when timer is up
        }
        t++;
    }

    // draw man objects
    while (k < man.size()){                                     //iterating over the man vector to make the object 
        if (k==0){                                              //initial object creation
    
        man[k]->draw();                                         //calling the draw function
        
        //move man object left
        if (left==true){                                        //checking if the left button is pressed by the user
            if ( (man[k] ->moverRect.x - 130) < 0 )             //checking for the corner of the screen
                {man[k] ->moverRect.x = 0;}                     //the man object moves left
            else {man[k] ->  moverRect.x -= 10;}                //the man object moves left with smaller increments here for smoothen movement
                left = false;}                                  //flag variable for left key set back to false
        
        //move man object right
        if (right==true){                                       //checking if the right button is pressed by the user
            if ( (man[k] ->moverRect.x + 130) > 980)            //checking for the corner of the screen
                {man[k] ->moverRect.x = 980;}                   //the man object moves right
            else{man[k] ->  moverRect.x += 10;}                 //the man object moves right with smaller increments here to smoothen movement
                right = false;}                                 //flag variable for right key set back to false
        
        //jump man object
        if (jumps==true){                                       //checks if up button is pressed by the user
            man[k] -> check = true;                             //flag variable for jump set to true
            jumps = false;}                                     //flag variable for up key set back to false
        
        //move or jump man object
        if (man[k] -> check ==true){                            //checks if the flag variable for jump is true
        man[k]->jump(chardraw);}                                //calling the jump function
        else{
        man[k]->moving(chardraw);}  }                           //calling the Move function
        k++;}                                                   //incrementing the counter variable
    t = 0;


    // draw lives
    while (t < living.size()){                                 //iterating over the lives vector to make the life objects 
        living[t].draw();                                      //drawing the lives
        if (life_check == true){                               //decreasing a life due to a collision
            --living[t];                                       //operator overloading to decrease the lives
            life_check = false;                                //flag variable set back to false
        }
        if (life_upgrade == true){                             //gain a life by collecting health collectible
            ++living[t];                                       //operator overloading to increment the lives
            life_upgrade = false;                              //flag variable set back to false
        }                                                             
        if (living[t].l_left < 1){                             //checking if all lives are lost 
            lost_check = true ;                                //all lives lost -> game losing condition set to true
        }         
        t++;                                                   //incrementing the counter variable
        }
    t = 0;
    

    // draw health collectibles
    while (t < health.size()){                                 //iterating over the health collectibles vector to make the object 
        health[t]->draw();                                     //draw the bottom running health collectibles
        health[t]->move();                                     //moving the bottom running health collectibles
        if (((abs(man[0]->moverRect.x-(health[t]->moverRect.x))<12) && (abs(man[0]->moverRect.y-(health[t]->moverRect.y))<12))){ //Collision condition by comparing x & y values
        life_upgrade = true;                                   //flag variable set to true
        life_check = false;                                    //flag variable set to false
        delete health[t];                                      //deleting the object
        health.erase(health.begin() + t);                      //removing from the vector
        }
        t++;
    }
    t = 0; 

    // draw coins on the top bar
    while (t < Coins.size()){                                   //iterating over the top bar coins vector to make the coin objects 
        Coins[t].draw();                                        //drawing the top bar coins
        if (Coin_Check == true)                                 //coin collected condition true
        {++Coins[t];                                            //operator overloading to increase the coins' count                       
        Coin_Check = false;}
        if (Coins[t].counts > 10){
            win_check = true ;}                                 //10 coins collected -> game winning condition achieved
        t++;
        }
    t = 0;

    // draw bottom running coins
    while (t < Coin_Bottom.size()){                                 //iterating over the bottom coins vector to make the object 
        Coin_Bottom[t]->draw();                                     //draw the bottom running coins
        Coin_Bottom[t]->move();                                     //moving the bottom running coins
        if (((abs(man[0]->moverRect.x-(Coin_Bottom[t]->moverRect.x))<12) && (abs(man[0]->moverRect.y-(Coin_Bottom[t]->moverRect.y))<12))){ //Collision condition by comparing x & y values
        Coin_Check = true;                                          //flag variable set to true
        delete Coin_Bottom[t];                                      //deleting the coin object
        Coin_Bottom.erase(Coin_Bottom.begin() + t);                 //removing from the vector
        }
        t++;
    }

    // draw obstacles
    for (Unit* x: things){                                          //iterationg over Unit* type list for the rest of the obstacles (grenades, police, car obstacles)
        x->draw();                                                  //drawing the obstacles
        x->move();                                                  //moving the obstacles
        if ((x->moverRect.x<0) || (x->moverRect.y>515)){            //end of the screen
            things.remove(x);}                                      //remove
        
        if (((abs(man[0]->moverRect.x-(x->moverRect.x))<20) && (abs(man[0]->moverRect.y-(x->moverRect.y))<20))){    //collision condition by comparing x & y values
            cout<<"collision occured"<<endl;
            life_check = true;                                      //life lost
            explosion ex(x->moverRect.x, x->moverRect.y);           
            explosive.push_back(ex);                                //explosion object pushed in explosive vector
            things.remove(x);}                                      //removing the obstacle vector
        }   
    } 

void RunningMan::createObject(bool charflag)                        //creates and pushes all the objects to vectors
{
    if (counter == 0){                                              //counter variable to create objects only once
        if (man.size()<1){                                          
        Man *man1 = new Man(charflag);                              //creates one man object pointer
        man.push_back(man1);}                                       

        if (living.size()<1){
        lives liv;                                                  //creates one life object
        living.push_back(liv);}

        if (Coins.size()<1){                    
        coins_b cin;                                                //creates the top bar coins object
        Coins.push_back(cin);}

        counter++ ;                                                 //incrementing the counter variable
    }

    tick ++;                                                        //delay counter variable

    if (tick >25){                                                  //delay counter 
    cout << "created"<<endl;
    int number = (rand() % 20);                                     //random number generator
    if (number == 0 || number == 4)                 
        {
            coins_a *app1 = new coins_a();                          //bottom coins object creation
            Coin_Bottom.push_back(app1);                            //push to the vector
        }
        else if (number ==  1 || number == 2 || number == 3)
        {
            PoliceMan *pol_man  = new PoliceMan();                  //police object creation
            things.push_back(pol_man);                              //push to the vector
        }
        else if (number == 4 || number == 5){
            Grenade *Bomb = new Grenade();                          //grenade object creation
            things.push_back(Bomb);                                 //push to the vector
        }
        else if (number ==  6 || number == 7 ){
            carobstacle *car1 = new carobstacle();                  //car object creation
            things.push_back(car1);                                 //push to the vector
        }
        else if ( number == 8 ||  number == 9){                     
            Drug1 *dealer1 = new Drug1();                           //drug object creation
            things.push_back(dealer1);                              //push to the vector
        }
        else if ( number == 10 ||  number == 11){                       
            Drug2 *dealer2 = new Drug2();                           //drug dealer object creation                 
            things.push_back(dealer2);                              //push to the vector
        }
        else if ( number == 13 ||  number == 14){
            Drug3 *dealer3 = new Drug3();                           //drug dealer object creation
            things.push_back(dealer3);                              //push to the vector
        }
        else if (number == 12){
            healthpickup *health1 = new healthpickup();             //health object creation
            health.push_back(health1);                              //push to the vector
        }

    tick = 0;}
}

void RunningMan::emptying(){                                        //clears the vectors and deletes the pointers
    for(auto&& i : things){                        
	delete i;}                                                      //deleteing the pointers in objects list from the memory
    things.clear();                                                 //removes them from the vector
    for(auto&& i : man){
	delete i;}                                                      //deletes the pointers in man vector from the memory    
    man.clear();                                                    //removes them from the vector
    for(auto&& i : Coin_Bottom){
	delete i;}                                                      //deletes the pointers in coins vector from the memory
    Coin_Bottom.clear();                                            //removes them from the vector
    for(auto&& i : health){
        delete i;}                                                      //deletes the pointers in health vector from the memory
    health.clear();                                                 //removes them from the vector   
    explosive.clear();                                              //removes the explosives' objects from the vector
    Coins.clear();                                                  //Removes the coins' objects from the vector
    living.clear();                                                 //Removes the lives object from the vector    
    
}

RunningMan :: ~RunningMan(){                        //destructor to remove the objects of this class
}

