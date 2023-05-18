#include "coins_b.hpp"
#include <iostream>
//Top Bar coins_b implementation will go here.

coins_b::coins_b(){
    // src coorinates found using spritecow
    moverRect = {20,130, 50, 50}; // setting the values
     // setting x and y values
    srcRect = {120, 117, 372, 357}; // setting the values
}

void coins_b::operator++(){              //operator overloading done
	counts++;                           //count increases at "++"
}

void coins_b::draw(){                          //draws the object
    moverRect = {22, 80, 50, 50};              //it draws the lines in a line or column
	for(int i=0 ; i<counts ; i++){
		SDL_RenderCopy(Drawing::gRenderer, Drawing::collectiblecoin, &srcRect, &moverRect);  
		moverRect.x+=40;		    //done to allow another heart to be made and be visible 
	}
}

coins_b :: ~coins_b(){              //destructor to delete the instance
}