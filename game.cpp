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
//LINHAS_MAPA = 20, COLUNAS_MAPA = 28;
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


/*	FIM	*/

#include "Unidade.cpp"

//inicializando uma unidade pra testar
Unidade* unit1 = NULL;
Unidade* unit2 = NULL;
Unidade* unidadeSelecionada = NULL;

int initialize()
{
	/*	Setando coisas	*/

    bool quit = false;

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

	if(unit1 != NULL)
		delete(unit1);

    //Quit SDL
    SDL_Quit();

	return 1;
}

//function of game main loop

int	updateTime()
{
	
}

int receiveNetworkMessages()
{

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

			if( event.key.keysym.sym == SDLK_1 ) 
				unit1 = new Unidade(10, 10, SOLDADO);
			
			if( event.key.keysym.sym == SDLK_2 ) 
				unit2 = new Unidade(2, 2, NAVIO);

			if(event.key.keysym.sym == SDLK_3)			
			unidadeSelecionada = unit1;

			if(event.key.keysym.sym == SDLK_4)			
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
        if( event.type == SDL_QUIT )	//If the user has Xed out the window
        {
            quit = true;
        }
    }

	return 1;
}

int tratarColisoes()
{
	
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
}

int do_logic()
{	
	tratarColisoes();
	atualizarEstados();

	return 1;
}

int do_drawing()
{
	/*if(scenarioAtual==TELA_INICIAL)
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
	else*/ scenarioAtual=INICIO;
	if(scenarioAtual==INICIO)
	{
		SDL_FillRect(screen, NULL, 0xFFFFFF);	//limpando tela anterior colocando a cor branca no lugar

		enum {
			AZUL,
			MARROM,
			VERDE,
			AMARELO,
			BRANCO
		};
		Uint32 cores[] = {0x0000FF, 0x9F6F2F, 0x00CC00, 0xFFFF00, 0xFFFFFF};		//correspondendo as cores definidas no enum

		//array que guardara valores representativos da cor (0 - Azul (agua), 1 - marrom (Terra), 2 - Verde (floresta), 3 - Amarelo (deserto), 4 - Branco (neve))
		/*int mapaMundi[LINHAS_MAPA][COLUNAS_MAPA] = {{0, 0, 0, 0, 0},
													{0, 2, 2, 2, 0},
													{0, 2, 1, 2, 0},
													{0, 2, 2, 2, 0},
													{0, 0, 0, 0, 0}};*/
		/*int mapaMundi[LINHAS_MAPA][COLUNAS_MAPA] = {{AZUL, AZUL, 	AZUL, 	AZUL, 	AZUL},
													{AZUL, VERDE, 	VERDE, 	VERDE, 	AZUL},
													{AZUL, VERDE, 	MARROM, VERDE, 	AZUL},
													{AZUL, VERDE, 	VERDE, 	VERDE, 	AZUL},
													{AZUL, AZUL, 	AZUL, 	AZUL, 	AZUL}};		*/

		for(int i = 0; i<LINHAS_MAPA; i++)
		{
			for(int j = 0; j<COLUNAS_MAPA; j++)
			{
				rect.x = j*30;
				rect.y = i*30;
				rect.w = 30;
				rect.h = 30;

				SDL_FillRect(screen, &rect, cores[mapaMundi[i][j]]);
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

