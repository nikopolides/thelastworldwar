#include "globals.h"

//The event structure that will be used
SDL_Event event;

//utilizarei para fazer os recortes
SDL_Rect rect;

bool quit = false;

int quadroEstado = 0;

ImageHandlerSDL* ImageHandlerSDLObj = NULL;
Draw* drawObj = NULL;
Random* randomObj = NULL;
