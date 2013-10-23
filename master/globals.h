#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL/SDL.h"
#include "ImageHandlerSDL.h"
#include "Draw.h"
#include "Random.h"

extern SDL_Event event;

extern SDL_Rect rect;

extern bool quit;

extern int quadroEstado;

extern ImageHandlerSDL* ImageHandlerSDLObj;
extern Draw* drawObj;
extern Random* randomObj;


#endif
