/*This source code copyrighted by Lazy Foo' Productions (2004-2012)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Funcoes com informacoes especificas deste jogo
#include "game.h"

int main()
{
bool quit = false;
	
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
		
		quit = true;
    }

	finalize();

    return 0;
}

