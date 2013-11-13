#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "ImageHandlerSDL.h"
#include "SDL/SDL_mixer.h"
#include "Draw.h"
#include "Random.h"
#include "Timer.h"

extern SDL_Surface *screen;
extern SDL_Event event;
extern SDL_Rect rect;


//The font that's going to be used 
extern TTF_Font *font; 
extern TTF_Font *fontMenu;

extern bool quit;
extern int quadroEstado;
extern const int FRAMES_PER_SECOND;
extern int frame;

extern ImageHandlerSDL* ImageHandlerSDLObj;
extern Draw* drawObj;
extern Random* randomObj;
extern Timer* timer;

#endif
