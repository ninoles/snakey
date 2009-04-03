/*
Snakey, a snake game in C++/SDL

Copyright (C) Hans-Kristian Arntzen <maister 'at' archlinux.us>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/


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



	

	
