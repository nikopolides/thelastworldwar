#ifndef UNIDADE_H
#define UNIDADE_H

#include "Draw.h"
#include "globals.h"
#include "globalsGame.h"
#include <string>

class Nacao;

class Unidade
{
	public:
		int posX;	//tile X do mapa onde atualmente habita
		int posY;	//tile Y do mapa onde atualmente habita
		int tipo;	//aviao,navio,soldado,canhao,etc...

		Nacao* nacao;

		int forca;
		bool isDead;

		bool selecionado;

		Unidade(int, int, int, int, Nacao*);
		int show();
		int attack(Unidade *); 
};

#endif
