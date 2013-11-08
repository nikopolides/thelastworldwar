#include "globalsGame.h"

int scenarioAtual = TELA_INICIAL;
Uint32 cores[] = {0x0000FF, 0x9F6F2F, 0x00CC00, 0xFFFF00, 0xFFFFFF};		//correspondendo as cores definidas no enum
int modo = MODO_NORMAL;

//The surfaces that will be used
SDL_Surface *screen = NULL;
SDL_Surface *logoEmpresa = NULL;
SDL_Surface *logoJogo = NULL;
SDL_Surface *logoRecursos = NULL;
SDL_Surface *menu = NULL;
SDL_Surface *classificacaoIndicativa = NULL;
SDL_Surface *mapa = NULL;


//carregando imagem das unidades
SDL_Surface *civilizationUnits = NULL;

Cenario* cenario = NULL;

/*
//inicializando uma unidade pra testar
Unidade* unit1 = new Unidade(10, 10, SOLDADO, 10);
Unidade* unit2 =  new Unidade(2, 2, NAVIO, 10);
Unidade* unidadeSelecionada = unit1;
*/
