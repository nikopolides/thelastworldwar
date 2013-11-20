#ifndef UNIDADE_H
#define UNIDADE_H

#include "Draw.h"
#include "globals.h"
#include "globalsGame.h"
#include <string>

class Nacao;
class Tile;

class Unidade
{
	public:
		int posX;	//tile X do mapa onde atualmente habita
		int posY;	//tile Y do mapa onde atualmente habita
		int tipo;	//aviao,navio,soldado,canhao,etc...

		Nacao* nacao;

		int qtdMovimentos;
		int ambiente;			//1 terra, 2 agua, 3 ambos
		
		int forca;
		bool isDead;

		bool selecionado;

		Unidade(int, int, int, int, Nacao*, int, int);
		int show();
		int attack(Unidade *); 
		bool canMove(Tile* tileDestino);
};

#endif
