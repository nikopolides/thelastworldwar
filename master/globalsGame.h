#ifndef GLOBALSGAME_H
#define GLOBALSGAME_H

#include "SDL/SDL.h"
#include "Cenario.h"
#include "Unidade.h"

//cenarios
enum {
	TELA_INICIAL,
	MENU_INICIAL,
	INICIO				//trabalhar nesta para fazer a proxima entrega
};

//carregando cores dos tiles do mapa-mundi
enum {
	AZUL,		//oceano
	MARROM,		//terra
	VERDE,		//floresta
	AMARELO,	//areia
	BRANCO,		//neve

	PRETO		//unidade
};

//modo de apresentacao desse mapa de bits
enum {
	MODO_NORMAL,
	MODO_QUADRADOS_PREENCHIDOS,
	MODO_QUADRADOS,
	MODO_CIRCULOS
};

extern int scenarioAtual;

extern Uint32 cores[];		//correspondendo as cores definidas no enum

extern int modo;

//The surfaces that will be used
extern SDL_Surface *screen;
extern SDL_Surface *logoEmpresa;
extern SDL_Surface *logoJogo;
extern SDL_Surface *logoRecursos;
extern SDL_Surface *classificacaoIndicativa;
extern SDL_Surface *menu;

//carregando imagem das unidades
extern SDL_Surface *civilizationUnits;

extern Cenario* cenario;

/*
//inicializando uma unidade pra testar
extern Unidade* unit1;
extern Unidade* unit2;
extern Unidade* unidadeSelecionada;
*/

/*	FIM	*/

#endif
