#ifndef GAME_H
#define GAME_H

#include <iostream>

using namespace std;

#include "biblioteca.h"
#include "globalsGame.h"

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
