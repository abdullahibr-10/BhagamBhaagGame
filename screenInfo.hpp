#include <iostream>

using namespace std;

class screenInfo{
    static screenInfo *instance;            //a static pointer to the singleton object of the screenInfo class
    int SCREEN_WIDTH = 1000;                //integer that stores the width of the game screen.
    int SCREEN_HEIGHT = 600;                //an integer that stores the height of the game screen.
    
    screenInfo();                           //private constructor so that no objects can be created, this prevents the creation of more than one instance of the screenInfo class, the getInstance() function is used to get the created object or create a new one if not already available.
    
    public:
    static screenInfo* getInstance() {      //static function that returns the singleton instance of the screenInfo class or create a new instance if one does not already exist
        if (!instance)
        instance = new screenInfo;
        return instance;
   }
    int getWidth();                     //function to get the SCREEN_WIDTH value
    int getHeight();                    //function to get the SCREEN_HEIGHT value
    void setData(int w, int h);         //function to change/set the values of width or height if needed
    ~screenInfo();                      //destructor for the screenInfo class
};


