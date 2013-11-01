/* Setando variaveis importantes globais */

//The attributes of the screen
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;
const int FRAMES_PER_SECOND = 20;

//The surfaces that will be used
SDL_Surface *screen = NULL;
SDL_Surface *logoEmpresa = NULL;
SDL_Surface *logoJogo = NULL;

//carregando imagem das unidades
SDL_Surface *civilizationUnits = NULL;

//The event structure that will be used
SDL_Event event;

//utilizarei para fazer os recortes
SDL_Rect rect;

bool quit = false;

int quadroEstado = 0;

//cenarios
enum {
	TELA_INICIAL,
	MENU_INICIAL,
	INICIO				//trabalhar nesta para fazer a proxima entrega
};
int scenarioAtual = TELA_INICIAL;

//carregando tiles do mapa-mundi
enum {
	AZUL,		//oceano
	MARROM,		//terra
	VERDE,		//floresta
	AMARELO,	//areia
	BRANCO,		//neve

	PRETO		//unidade
};
Uint32 cores[] = {0x0000FF, 0x9F6F2F, 0x00CC00, 0xFFFF00, 0xFFFFFF};		//correspondendo as cores definidas no enum

const int LINHAS_MAPA = 22;
const int COLUNAS_MAPA = 33;
int mapaMundi[LINHAS_MAPA][COLUNAS_MAPA] = 
		   {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

//modo de apresentacao desse mapa de bits
enum {
	MODO_NORMAL,
	MODO_QUADRADOS_PREENCHIDOS,
	MODO_QUADRADOS,
	MODO_CIRCULOS
};
int modo = MODO_NORMAL;

/*	FIM	*/

#include "Unidade.cpp"

//inicializando uma unidade pra testar
/*Unidade* unit1 = NULL;
Unidade* unit2 = NULL;
Unidade* unidadeSelecionada = NULL;*/
Unidade* unit1 = new Unidade(10, 10, SOLDADO);
Unidade* unit2 =  new Unidade(2, 2, NAVIO);
Unidade* unidadeSelecionada = unit1;

int initialize()
{
	/*	Setando coisas	*/

    quit = false;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		cout << "Problemas ao inicializar sistemas e subsistemas do SDL" << endl;    
		return -1;
	}

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
		cout << "Problemas inicializando o video" << endl;
        return -2;
    }

    //Set the window caption
    SDL_WM_SetCaption( "The World Last War", NULL );	

    //Load the images
	logoEmpresa = load_image( "img_gamaSoft.jpg" );
    logoJogo = load_image( "coollogo_com-301376238.jpg" );
	civilizationUnits = load_image( "civilization2Units.png" );

	return 1;	//sucess
}

int finalize()
{
    //Free the surfaces
    SDL_FreeSurface( logoEmpresa );
    SDL_FreeSurface( logoJogo );
    SDL_FreeSurface( civilizationUnits );

	unidadeSelecionada = NULL;

	if(unit1 != 0)
		delete(unit1);
	if(unit2 != 0)
		delete(unit2);

    //Quit SDL
    SDL_Quit();

	return 1;
}

//function of game main loop

int	updateTime()
{
	return 1;
}

int receiveNetworkMessages()
{
	return 1;
}

int do_miscBefore()
{
	updateTime();
	receiveNetworkMessages();

	return 1;
}

int get_inputs()
{
    while( SDL_PollEvent( &event ) )
    {
		if( event.type == SDL_KEYDOWN )
		{
			if( event.key.keysym.sym == SDLK_ESCAPE ) 
				quit = true;

			if(unidadeSelecionada != 0)
			{
				if(event.key.keysym.sym == SDLK_1)			
					unidadeSelecionada = unit1;

				if(event.key.keysym.sym == SDLK_2)			
					unidadeSelecionada = unit2;

				if( event.key.keysym.sym == SDLK_LEFT ) 
					(*unidadeSelecionada).posX -= 1;
				if( event.key.keysym.sym == SDLK_RIGHT ) 
					(*unidadeSelecionada).posX += 1;
				if( event.key.keysym.sym == SDLK_UP ) 
					(*unidadeSelecionada).posY -= 1;
				if( event.key.keysym.sym == SDLK_DOWN ) 
					(*unidadeSelecionada).posY += 1;
			}

			//alternando modo do mapa
			if(event.key.keysym.sym == SDLK_0)
			{
				++modo;
				modo = (modo) % 4;		//4 modos
			}
		}

        if( event.type == SDL_QUIT )	//If the user has Xed out the window
        {
            quit = true;
        }
    }

	return 1;
}

int tratarColisoes()
{
	return 1;	
}

int atualizarEstados()
{
	quadroEstado++;
	if(scenarioAtual==TELA_INICIAL)
	{
		switch(quadroEstado)
		{
			case 2:
					SDL_FillRect(screen, NULL, 0xFFFFFF);

					apply_surface( 200, 100, logoEmpresa, screen);
					SDL_Delay(2000);
					break;
			case 3:
					SDL_FillRect(screen, NULL, 0xFFFFFF);

					apply_surface( 200, 100, logoEmpresa, screen);
					SDL_Delay(2000);
					scenarioAtual = INICIO;					//trabalhando com esse para esta entrega
					break;
		}
	}		
	return 1;
}

int do_logic()
{	
	tratarColisoes();
	atualizarEstados();

	return 1;
}

int do_drawing()
{
	if(scenarioAtual==TELA_INICIAL)
	{
		switch(quadroEstado)			//switch para diferenciar
		{
			case 1:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					apply_surface( 200, 100, logoEmpresa, screen);
					break;
			case 2:
			default:
					SDL_FillRect(screen, NULL, 0x000000);
					apply_surface( 100, 270, logoJogo, screen );
					break;
		}
	}
	else scenarioAtual=INICIO;
	if(scenarioAtual==INICIO)
	{
		//limpando tela anterior colocando a cor branca no lugar
		SDL_FillRect(screen, NULL, 0xFFFFFF);	

		//desenhando mapa de bits de acordo ao modo
		for(int i = 0; i<LINHAS_MAPA; i++)
		{
			for(int j = 0; j<COLUNAS_MAPA; j++)
			{
				rect.x = j*30;
				rect.y = i*30;
				rect.w = 30;
				rect.h = 30;
				
				switch(modo)
				{
					case MODO_NORMAL:
					case MODO_QUADRADOS_PREENCHIDOS:
						SDL_FillRect(screen, &rect, cores[mapaMundi[i][j]]);
						break;
					case MODO_QUADRADOS:
						drawRect(screen, rect.x, rect.y, rect.w, rect.h, cores[mapaMundi[i][j]]);
						break;
					case MODO_CIRCULOS:
						drawCircle(screen, rect.x, rect.y, rect.w/2, cores[mapaMundi[i][j]], false);
						break;
				}
			}
		}

		if(unit1 != NULL)
			(*unit1).show();

		if(unit2 != NULL)
			(*unit2).show();
	}

	if( SDL_Flip( screen ) == -1 )
	{
		cout << "Nao conseguiu realizar a funcao SDL_Flip" << endl;
	    return -1;
	}

	return 1;
}

int sound()
{


	return 1;	
}

int sendNetworkMessages()
{


	return 1;	
}

int do_miscAfter()
{
	sound();
	sendNetworkMessages();

	return 1;
}

