#ifndef UNIDADE_H
#define UNIDADE_H

#include "Draw.h"
#include "globals.h"
#include "globalsGame.h"
#include <string>

class Unidade
{
	public:
		int posX;	//tile X do mapa onde atualmente habita
		int posY;	//tile Y do mapa onde atualmente habita
		int tipo;	//aviao,navio,soldado,canhao,etc...

		string nacao;	//Nacao que a Unidade faz parte
		
		int forca;
		bool isDead;

		Unidade(int, int, int, int, string);
		int show();
		int attack(Unidade *); 
};

#endif
