#include "globalsGame.h"

int scenarioAtual = TELA_INICIAL;
Uint32 cores[] = {0x0000FF, 0x9F6F2F, 0x00CC00, 0xFFFF00, 0xFFFFFF};		//correspondendo as cores definidas no enum
int modo = MODO_NORMAL;

int contadorMovimentosSoldado = 5;
int contadorMovimentosNavio = 3;

//The surfaces that will be used
SDL_Surface *logoEmpresa = NULL;
SDL_Surface *logoJogo = NULL;
SDL_Surface *logoRecursos = NULL;
SDL_Surface *menu = NULL;
SDL_Surface *classificacaoIndicativa = NULL;
SDL_Surface *mapa = NULL;

SDL_Surface *messageRecursos = NULL;
SDL_Surface *messageUnidades = NULL;


char scoreRecursosNacao1[300];
char scoreUnidadesNacao1[300];	
	


//carregando imagem das unidades
SDL_Surface *civilizationUnits = NULL;

Cenario* cenario = NULL;

