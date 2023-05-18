#include "game.hpp"
#include "RunningMan.hpp"
#include "drawing.hpp"
#include "screenInfo.hpp"
#include "Unit.hpp"
//done to include a particular image in the game

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;
SDL_Texture* Drawing::collectiblecoin = NULL;
SDL_Texture* Drawing::life = NULL;
SDL_Texture* Drawing::bomb = NULL;
SDL_Texture* Drawing::exp = NULL;
SDL_Texture* Drawing::police = NULL;
SDL_Texture* Drawing::Ride_back = NULL;
SDL_Texture* Drawing::DRUG1 = NULL;
SDL_Texture* Drawing::DRUG2 = NULL;
SDL_Texture* Drawing::DRUG3 = NULL;
SDL_Texture* Drawing::HealthPickup = NULL;

//Initialize pointer to zero so that it can be initialized in first call to getInstance
screenInfo *screenInfo::instance = 0;

//Getting the instance of SINGLETON Design Pattern
screenInfo* screen = screen->getInstance();

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
        {
            printf( "Unable to open audio: %s\n", Mix_GetError());
            success=false;
        }

		//Create window using SINGLETON Design Pattern
		gWindow = SDL_CreateWindow( "BHAGAM BHAG!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen->getWidth(), screen->getHeight(), SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadGrid(bool char_flag)       //this is the main game one. This is where all the objects will come and the user can play.
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("main_music.mp3");
	// loading all the pictures

    if (char_flag == 0)
	{
		Drawing::assets = loadTexture("assets.png");
	}
	else if (char_flag == 1)
	{
		Drawing::assets = loadTexture("babla.png");
	}

	Drawing::police = loadTexture("Police Sprites new.png");
	Drawing::exp = loadTexture("exp.png");
	Drawing::collectiblecoin = loadTexture("collectiblecoin.png");
	Drawing::life = loadTexture("life.png");
	Drawing::bomb = loadTexture("bomb.png");
	Drawing::Ride_back = loadTexture("Ride_back.png");
	Drawing::DRUG1 = loadTexture("dd1.png");
	Drawing::DRUG2 = loadTexture("dd2.png");
	Drawing::DRUG3 = loadTexture("dd3.png");
	Drawing::HealthPickup = loadTexture("HealthPickup.png");
    gTexture = loadTexture("bg.png");
	if(Drawing::assets==NULL || Drawing::police==NULL || Drawing::collectiblecoin==NULL || Drawing::life==NULL|| Drawing::bomb==NULL || Drawing::Ride_back==NULL || Drawing::DRUG1==NULL || Drawing::DRUG2==NULL || Drawing::DRUG3==NULL || Drawing:: HealthPickup == NULL || gTexture==NULL)
    { 
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	Mix_PlayMusic(music,0);
	return success;
}

bool Game::loadMedia()   		//this function is called to display the main menu
{
	//Loading success flag
	bool success = true;
	music=Mix_LoadMUS("music.mp3");               //we introduced a song to make the game more lively
    gTexture = loadTexture("menu.png");					//image of the menu
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	if(music == NULL)
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	Mix_PlayMusic(music,0);
	return success;
}


bool Game::loadSelection()   		//this function is called to display the main menu
{
	//Loading success flag
	bool success = true;
	music=Mix_LoadMUS("music.mp3");               //we introduced a song to make the game more lively
    gTexture = loadTexture("CharSel.png");					//image of the menu
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	if(music == NULL)
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	Mix_PlayMusic(music,0);
	return success;
}


bool Game::loadWIN()		//this one is when the person completes the game and wins
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("maloom.mp3");
    gTexture = loadTexture("won.png");        //loading winning screen
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	Mix_PlayMusic(music,0);
	return success;
}

bool Game::loadLOST()                     //this one is when the person completes the game and loses
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("miracle.mp3");
    gTexture = loadTexture("lost.png");            //loading losing screen
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	Mix_PlayMusic(music,0);
	return success;
}


void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(Drawing::police);
	Drawing::police=NULL;
	SDL_DestroyTexture(Drawing::collectiblecoin);
	Drawing::collectiblecoin=NULL;
	SDL_DestroyTexture(Drawing::life);
	Drawing::life=NULL;
	SDL_DestroyTexture(Drawing::bomb);
	Drawing::bomb=NULL;
	SDL_DestroyTexture(Drawing::exp);
	Drawing::exp=NULL;
	SDL_DestroyTexture(Drawing::Ride_back);
	Drawing::Ride_back=NULL;
	SDL_DestroyTexture(Drawing::DRUG1);
	Drawing::DRUG1=NULL;
	SDL_DestroyTexture(Drawing::DRUG2);
	Drawing::DRUG2=NULL;
	SDL_DestroyTexture(Drawing::DRUG3);
	Drawing::DRUG3=NULL;
	SDL_DestroyTexture(gTexture);
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;
	SDL_Event e;

	RunningMan runningman;
	bool charFlag;

	while( !quit )
	{
		
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
				cout<<quit;
			}


			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if (state == 0 and xMouse>=110 and xMouse<= 230 and yMouse>=550 and yMouse<=590){  
					// this checks whether we are on the main page and whether we clicked the play button
					// in which case the game would start
					state = 1;
					loadSelection();
					//loadGrid();        //loads the gaming screen
				}

				else if (state == 0 and xMouse>=580 and xMouse<= 710 and yMouse>=540 and yMouse<=580){  
					// this checks whether we are on the main page and whether we clicked the play button
					// in which case the game would start
					quit = true;
				}

                else if (state == 1){  
					// this checks whether we are on the main page and whether we clicked the play button
					// in which case the game would start
					if (xMouse >= 182 and xMouse <= 437 and yMouse >= 339 and yMouse <= 723)
					{
						charFlag = 0;
						state = 2;
					    loadGrid(charFlag);        //loads the gaming screen
				    }

					else if (xMouse >= 498 and xMouse <= 747 and yMouse >= 339 and yMouse <= 723)
					{
						charFlag = 1;
						state = 2;
					    loadGrid(charFlag);        //loads the gaming screen
					}
				}
					


				else if (state == 4){
					// this one is for when the game is finished and you choose whether to continue or end
					if (xMouse>=464 and xMouse<= 600 and yMouse>=476 and yMouse<=525){
						quit = true; //game ended
					}
					else if(xMouse>=314 and xMouse<= 430 and yMouse>=472 and yMouse<=527){
						state = 0;
						runningman.counter = 0;        //state changed to the main menu one
						loadMedia();			//main menu opened
					}
				}
				
			}
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP]) { 
				runningman.jumps = true;           //for a certain key, a certain check becomes true
			}
			if (state[SDL_SCANCODE_RIGHT]) { 
				runningman.right = true;            //for a certain key, a certain check becomes true
			}
			if (state[SDL_SCANCODE_LEFT]) { 
				runningman.left = true;	           //for a certain key, a certain check becomes true
			}   
		}
		if (runningman.win_check == true){		//this condition checks for whether game is won
			loadWIN();
			runningman.emptying();              // empties everything
			state = 4;
			runningman.win_check = false;
			}
		if (runningman.lost_check == true){     //this condition checks for whether game is lost
			loadLOST();
			runningman.emptying();					// empties everything
			state = 4;
			runningman.lost_check = false;
			}

		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		if (state ==2){      // these functions are only called when the user is playing the game
		runningman.drawObjects(charFlag);
		runningman.createObject(charFlag);}

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(60);	//causes sdl engine to delay for specified miliseconds
	}
			
}
