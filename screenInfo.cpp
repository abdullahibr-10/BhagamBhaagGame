#include "screenInfo.hpp"
#include <iostream>

using namespace std;

screenInfo::screenInfo(){                           //Constructor to set the values
    int SCREEN_WIDTH = 1000;
    int SCREEN_HEIGHT = 600;
}

int screenInfo::getWidth() {                        //Function to get the SCREEN_WIDTH data
    return this ->SCREEN_WIDTH;
}
int screenInfo::getHeight() {                       //Function to get the SCREEN_HEIGHT data
    return this ->SCREEN_HEIGHT;
}

void screenInfo::setData(int w, int h) {            //Function to change/set the data if needed
    this -> SCREEN_WIDTH = w;
    this -> SCREEN_WIDTH = h;
}

screenInfo::~screenInfo(){                          //Destructor to remove the object
}

