#include "globals.h"

SDL_Surface *screen = NULL;
//The event structure that will be used
SDL_Event event;
//utilizarei para fazer os recortes
SDL_Rect rect;

TTF_Font *font = NULL; 
TTF_Font *fontMenu = NULL;
bool quit = false;
int quadroEstado = 0;
const int FRAMES_PER_SECOND = 20;
int frame = 0;

ImageHandlerSDL* ImageHandlerSDLObj = NULL;
Draw* drawObj = NULL;
Random* randomObj = NULL;
Timer* timer = NULL;
bool meuTurno = false;
