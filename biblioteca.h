#ifndef UNIDADE_H
#define UNIDADE_H

#include <sstream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

extern string intToString(int x);
extern void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
extern SDL_Surface *load_image( std::string filename );


#endif
