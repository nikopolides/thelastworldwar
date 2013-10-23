#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

//Funcoes que coletei/modifiquei
#include "biblioteca.h"

//Bibliotecas
#include "ImageHandlerSDL.h"
#include "Draw.h"
#include "Random.h"

//Funcoes com informacoes especificas deste jogo
#include "game.h"
#include "globals.h"
#include "globalsGame.h"

int main()
{
	initialize();

    while( quit == false )		//main loop
    {
		//outras funcoes (rede, tempo)
		updateTime();
		receiveNetworkMessages();

		//get inputs
		get_inputs();
		//do Logic
		do_logic();	
		//do drawing
		do_drawing();

		//outras funcoes (som, rede, tempo)
		sound();
		sendNetworkMessages();
    }

	finalize();

    return 0;
}

