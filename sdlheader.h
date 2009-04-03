#include <string>
#ifdef __linux__
#include "SDL/SDL.h"
#endif
#ifdef __WIN32__
#include <SDL.h>
#endif
#define SQUARE_SIZE 60
#include <sstream>
#include <ctime>
#define SQUARE_QUANT 11

class coordinate
{
	public:
	int x;
	int y;
	
	static int n;
	
	coordinate()
	{
		x = SQUARE_SIZE*3 + n;
		y = SQUARE_SIZE*3;
		n += SQUARE_SIZE*SQUARE_QUANT;
	}
	coordinate(coordinate* d){
		srand((unsigned)time(0));
		while(true){
		x = ((rand()%SQUARE_QUANT)*SQUARE_SIZE);
		y = ((rand()%SQUARE_QUANT)*SQUARE_SIZE);
		if (x != d[0].x && y != d[0].y) break;
	 }
	}
};


SDL_Surface* load_image(std::string);
bool init();
SDL_Surface* load_files(std::string);
void clean_up(SDL_Surface*);

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
bool renderPicture(SDL_Surface*, SDL_Surface*,SDL_Surface*);
void updateCo(int x, int y);
bool collitionDetection(coordinate*);
std::string stringify(int x);
coordinate updateCoFood(coordinate, coordinate*);
void updateCaption();



	

	
