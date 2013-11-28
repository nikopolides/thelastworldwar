#ifndef DRAW_H
#define DRAW_H

#include "SDL/SDL.h"
#include <math.h>
#include <iostream>

using namespace std;

class Draw
{
	public:
		Draw();
		Uint32 getpixel(SDL_Surface *, int, int);
   		void putpixel(SDL_Surface *, int, int, Uint32);
		void drawLine(SDL_Surface *, float, float, float, float, Uint32);
		void drawRect(SDL_Surface *, float, float, float, float, Uint32);
		void drawCircle(SDL_Surface *, int, int, int, Uint32, bool);
		int apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
};

#endif
