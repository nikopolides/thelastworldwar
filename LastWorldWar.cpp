/*This source code copyrighted by Lazy Foo' Productions (2004-2012)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Funcoes que coletei/modifiquei
#include "biblioteca.cpp"

//Funcoes com informacoes especificas deste jogo
#include "game.cpp"

int main( int argc, char* args[] )
{

	initialize();

    while( quit == false )		//main loop
    {
		//outras funcoes (rede, tempo)
		do_miscBefore();

		//get inputs
		get_inputs();
		//do Logic
		do_logic();	
		//do drawing
		do_drawing();

		//outras funcoes (som, rede, tempo)
		do_miscAfter();
    }

	finalize();

    return 0;
}
