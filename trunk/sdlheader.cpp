#include "sdlheader.h"
#include <string>



int parts = 1;
int renderings = 0;
int totalScore = 1;


int coordinate::n = 0;
coordinate d[100];
coordinate foodCo(d);

	
SDL_Surface *screen = NULL;



const int SCREEN_WIDTH=SQUARE_SIZE*SQUARE_QUANT;
const int SCREEN_HEIGHT=SQUARE_SIZE*SQUARE_QUANT;
const int SCREEN_BPP=32;


SDL_Surface* load_image(std::string file)
{
	SDL_Surface *loadedImage = NULL;
	loadedImage = SDL_LoadBMP(file.c_str());
	SDL_Surface *optimizedImage = NULL;
	if (loadedImage != NULL){
		optimizedImage = SDL_DisplayFormat(loadedImage);
		
		SDL_FreeSurface(loadedImage);
		return optimizedImage;
	}
	return NULL;
}

bool init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
		return false;
	}
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	
	if (screen == NULL){
		return false;
	}
	
    SDL_WM_SetCaption(":'D", NULL);
	
	return true;
}


SDL_Surface* load_files(std::string picsource)
{
    
    SDL_Surface *source = load_image( picsource );
    
    if( source == NULL )
    {
        return NULL;    
    }
    
    return source;    
}


void clean_up(SDL_Surface* source)
{
    
    SDL_FreeSurface( source );
 
    
}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    
    SDL_Rect offset;
    
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}		

bool renderPicture(SDL_Surface *source, SDL_Surface *food, SDL_Surface *follower)
{
	if(!collitionDetection(d))
	{
		return false;
	}
	
	
	SDL_FillRect(screen, &screen->clip_rect, (unsigned int)0x00000000);
	
	apply_surface(foodCo.x,foodCo.y,food,screen);
	
	for(int a = parts-1; a >= 0 ; a--)
	{
		if(a == 0) apply_surface(d[a].x,d[a].y,source,screen);
		else apply_surface(d[a].x,d[a].y,follower,screen);
	}
	
	if(SDL_Flip(screen) == -1)
	{
		return false;
	}
	renderings++;
	updateCaption();
	return true;		
}

void updateCo(int x, int y)
{
	for(int a=parts-2; a >= 0; a--){
		d[a+1].x = d[a].x;
		d[a+1].y = d[a].y;
	}
	d[0].x += x;
	d[0].y += y;
}	

bool collitionDetection(coordinate *d)
{
	for(int b = 0; b < parts-1; b++)
	{
		for (int a = b+1; a < parts; a++)
		{
			if(d[b].x == d[a].x && d[b].y == d[a].y) return false;
		}
	}
	if (d[0].x < 0){
		d[0].x=SQUARE_SIZE*(SQUARE_QUANT-1);
	}
	if (d[0].x > SQUARE_SIZE*(SQUARE_QUANT-1)){
		d[0].x=0;	
	}
	
	if (d[0].y < 0){
		d[0].y = SQUARE_SIZE*(SQUARE_QUANT-1);
		}
	
	if (d[0].y > SQUARE_SIZE*(SQUARE_QUANT-1)){
		d[0].y = 0;
		}
	
	
	if (d[0].x == foodCo.x && d[0].y == foodCo.y){
		foodCo = updateCoFood(foodCo, d);
		parts += 1;
		
	}	
	return true;
}

std::string stringify(int x)
 {
   std::ostringstream o;
   o << x;
   return o.str();
 }

coordinate updateCoFood(coordinate surface, coordinate *d){
	srand((unsigned)time(0));
	bool hit;
	while(true){
		hit=false;
		surface.x = (rand()%SQUARE_QUANT)*SQUARE_SIZE;
		surface.y = (rand()%SQUARE_QUANT)*SQUARE_SIZE;
		
		for(int a=0; a <= parts; a++){
			if (surface.x == d[a].x && surface.y == d[a].y) hit=true;
			if (hit) break;
		}
		if(hit) continue;
		break;
	}
		return surface;
}

        
		
void updateCaption(){		
		std::string score;
		score = stringify(parts);
		score += " SNAEK(S)! :D ||";
		score += "  Count: ";
		score += stringify(renderings);
		score += " ||";
		score += "  SCORE: ";
		totalScore = parts*parts*1000/(renderings+20);
		score += stringify(totalScore);
		
	    SDL_WM_SetCaption(score.c_str(), NULL);
}
