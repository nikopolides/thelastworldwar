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

//The event structure that will be used
SDL_Event event;

//utilizarei para fazer os recortes
SDL_Rect rect;

bool quit = false;

int quadroEstado = 0;

//cenarios
enum {
	TELA_INICIAL,
	MENU_INICIAL
};
int scenarioAtual = TELA_INICIAL;

/*	FIM	*/



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

	return 1;	//sucess
}

int finalize()
{
    //Free the surfaces
    SDL_FreeSurface( logoEmpresa );
    SDL_FreeSurface( logoJogo );

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
			{ 
				quit = true;
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
					//scenarioAtual = MENU_INICIAL;
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
	if(scenarioAtual==TELA_INICIAL)
	{
		switch(quadroEstado)
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

