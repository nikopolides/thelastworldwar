#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
#include "Tile.h"
#include "Cenario.h"
#include "Unidade.h"
#include "globals.h"
#include "globalsGame.h"
#include "ImageHandlerSDL.h"
#include "Draw.h"
#include <iostream>

using namespace std;

extern int initializeCenario1();
extern int finalizeCenario1();

extern int initialize();
extern int finalize();

//outras funcoes (rede, tempo)
extern int updateTime();
extern int receiveNetworkMessages();

//get inputs
extern int get_inputs();

//do Logic
extern int tratarColisoes();
extern int atualizarEstados();
extern int do_logic();	

//do drawing
extern int do_drawing();

//outras funcoes (som, rede, tempo)
extern int sound();
extern int sendNetworkMessages();

#endif