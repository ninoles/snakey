#include "sdlheader.h"


SDL_Surface *message = NULL;
SDL_Surface *food = NULL;
SDL_Surface *messageFollower = NULL;
SDL_Event event;


int main(int argc, char* argv[])
{
	srand((unsigned)time(0));
	
	
	if(!init())
	{
		return 1;
	}
	if(!(message=load_files("awesome.bmp")))
	{
		return 1;
	}
	if(!(food=load_files("food.bmp"))){
		return 1;
	}
	if(!(messageFollower=load_files("follower.bmp"))){
		return 1;
	}
	
	
	
	
bool running=true;


enum directions { LEFT, RIGHT, UP, DOWN };
enum directions2 { LEFT2, RIGHT2, UP2, DOWN2 };
int direction=LEFT;
int direction2=LEFT2;


if(!renderPicture(message,food,messageFollower)) running=false;
int duration = 250;
int timer1 = 0;
int timer2 = 0;



while(running)   
{
  
  if(SDL_PollEvent(&event)){
    
	if(event.type == SDL_KEYDOWN){
		
		switch(event.key.keysym.sym){
		
		    case SDLK_UP: 
			 if (direction2 == DOWN) break;
			 direction = UP; break;
			case SDLK_DOWN:
			 if (direction2 == UP) break;
			 direction = DOWN; break;
	        case SDLK_LEFT: 
			 if (direction2 == RIGHT) break;
			 direction = LEFT; break;
			case SDLK_RIGHT:
			 if (direction2 == LEFT) break;
			 direction = RIGHT; break;
			default: break;	
		}
		
			
			
		
	}
	
	if(event.type == SDL_QUIT){
		running = false;
		clean_up(message);
		clean_up(food);
		return 0;
	}
	
  }
  else SDL_Delay(1);		
  
  
  timer1 = SDL_GetTicks();
  
  
  if(timer1 - timer2 > duration){	
  
  timer2 = timer1;
  if(duration > 150) duration--;
  
  switch (direction){
			case UP:
			updateCo(0,-SQUARE_SIZE); direction2 = UP; break;
			case DOWN:
			updateCo(0, SQUARE_SIZE); direction2 = DOWN; break;
			case LEFT:
			updateCo(-SQUARE_SIZE,0); direction2 = LEFT; break;
			case RIGHT:
			updateCo(SQUARE_SIZE,0); direction2 = RIGHT; break;
			default: break;
		}
		
		
			
		if(!renderPicture(message,food,messageFollower)) running=false;
		
	}	
			
}	
	SDL_Delay(1500);
	clean_up(message);
	clean_up(food);
	clean_up(messageFollower);
	SDL_Quit();
	return 0;
}

