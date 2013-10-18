#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

//Funcoes que coletei/modifiquei
#include "biblioteca.cpp"

//Bibliotecas
#include "ImageHandlerSDL.cpp"
#include "Draw.cpp"
#include "Random.cpp"

//Funcoes com informacoes especificas deste jogo
#include "game.cpp"

int main()
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

