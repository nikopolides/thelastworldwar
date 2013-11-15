#include "game.h"
#include "globalsGame.h" 
#include "Nacao.h"
#include "Unidade.h"
#include "SDL/SDL_ttf.h"

#define AVIAO 0
#define NAVIO 1
#define SOLDADO 2
#define CANHAO 3


Nacao* nacao1 = new Nacao(400,400,400,400,"Estados Unidos");
Nacao* nacao2 = new Nacao(400,400,400,400, "Siria");
Nacao* nacaoSelecionada = nacao1;

Unidade* unidadeSelecionada = NULL;
Unidade* unidadeAlvo = NULL;

Mix_Music *music = NULL;
Mix_Music *musicGame = NULL;
Mix_Music *musicaAtual = NULL;

int sound()
{
	

	return 1;	
}


//Funcao Menu
void selecionarMenu(){

	if(event.type == SDL_MOUSEBUTTONUP) 
	{
			
		int X = event.button.x;
		int Y = event.button.y;

		int tileX = X/30;
		int tileY = Y/30;

		//Abrir jogo
		if( (tileX>=10 && tileX<=19) && (tileY>=10 && tileY<=13) )
			scenarioAtual=INICIO;	
		//Sair	
		if( (tileX>=10 && tileX<=19) && (tileY>=21 && tileY<=24) )
			quit = true;
	
		}
}


//diferentes cenarios
int initializeCenario1()
{
	(*nacao1).exercitoAdd(new Unidade(3,3,SOLDADO,10,nacao1,5));
	(*nacao1).exercitoAdd(new Unidade(5,2,NAVIO,10,nacao1,3));
	
	(*nacao2).exercitoAdd(new Unidade(24,16,SOLDADO,10,nacao2,5));
	(*nacao2).exercitoAdd(new Unidade(20,18,NAVIO,10,nacao2,3));	
	

	const int LINHAS_MAPA = 24;
	const int COLUNAS_MAPA = 33;

	int **mapaMundi = (int**)calloc(LINHAS_MAPA*COLUNAS_MAPA, sizeof(int*));
	for(int i = 0; i<LINHAS_MAPA; i++)
	{
		mapaMundi[i] = (int*)calloc(COLUNAS_MAPA, sizeof(int));
	}

	//criando a variavel auxiliar apenas para aproveitar esta forma de declaracao de array com chaves, carregar de arquivo depois
	int auxMapaMundi[LINHAS_MAPA][COLUNAS_MAPA] = 
			 {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 4, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
				{0, 0, 4, 1, 1, 3, 1, 2, 4, 0, 5, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0},
				{0, 0, 4, 1, 1, 3, 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0},
				{0, 0, 4, 1, 6, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0},
				{0, 0, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 5, 4, 3, 4, 0, 4, 4, 4, 4, 4, 4, 2, 1, 1, 3, 1, 4, 5, 0},
				{0, 0, 0, 0, 4, 1, 4, 5, 0, 0, 0, 0, 0, 0, 0, 4, 2, 4, 0, 0, 0, 0, 0, 0, 4, 1, 1, 2, 3, 1, 4, 0, 0},
				{0, 0, 0, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4, 1, 4, 4, 1, 1, 1, 4, 0, 0},
				{0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0, 4, 1, 2, 1, 4, 0, 0},
				{0, 0, 0, 0, 0, 4, 1, 1, 2, 6, 1, 1, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4, 1, 4, 0, 0, 4, 1, 6, 4, 0, 0, 0},
				{0, 0, 0, 5, 0, 4, 1, 1, 2, 2, 1, 1, 4, 0, 0, 0, 4, 6, 3, 1, 1, 1, 4, 0, 0, 0, 4, 1, 4, 0, 4, 0, 0},
				{0, 0, 0, 0, 4, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 4, 4, 4, 3, 6, 4, 0, 0, 5, 0, 4, 0, 4, 6, 4, 0},
				{0, 0, 0, 0, 0, 4, 6, 1, 3, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 4, 2, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 4, 5},
				{0, 0, 0, 0, 0, 0, 4, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 4, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
				{0, 0, 0, 0, 5, 0, 4, 1, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 4, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 4, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 4, 1, 2, 6, 4, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 4, 1, 2, 3, 4, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 2, 3, 1, 1, 1, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	
	for(int i = 0; i<LINHAS_MAPA; i++)
	{
		for(int j = 0; j<COLUNAS_MAPA; j++)
		{
			mapaMundi[i][j] = auxMapaMundi[i][j];
		}
	}

	//criando o objeto e enviando o array com as posicoes deste cenario MAPA MUNDI
	cenario = new Cenario(COLUNAS_MAPA, LINHAS_MAPA);
	(*cenario).initialize(mapaMundi);

	//desalocando
	for(int i = 0; i<LINHAS_MAPA; i++)
	{ 	
		free(mapaMundi[i]);
	}
	free(mapaMundi);

	return 1;
}

int finalizeCenario1()
{
	(*cenario).finalize();
	delete(cenario);

	return 1;
}




//main loop functions
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

    //Initialize SDL_ttf 
    if( TTF_Init() == -1 ) 
	    return false;

	
	//Initialize Audio
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

	//The attributes of the screen
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;
	const int SCREEN_BPP = 32;

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

	music = Mix_LoadMUS( "soundtrack/musica1.ogg" );
	musicGame = Mix_LoadMUS( "soundtrack/musica2.ogg");

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
		cout << "Problemas inicializando o video" << endl;
        return -2;
    }

    //Set the window caption
    SDL_WM_SetCaption( "The World Last War", NULL );	

	//objetos principais
	ImageHandlerSDLObj = new ImageHandlerSDL();
	drawObj = new Draw();
	randomObj = new Random();
	timer = new Timer();

    //Load the images
	logoEmpresa = (*ImageHandlerSDLObj).load_image("images/gamaSoft.jpg",0);
  logoJogo = (*ImageHandlerSDLObj).load_image("images/logo.png",0);
	logoRecursos = (*ImageHandlerSDLObj).load_image("images/recursosTecnologicos.png",0);
	civilizationUnits = (*ImageHandlerSDLObj).load_image("images/unidades2.png",0);
	classificacaoIndicativa = (*ImageHandlerSDLObj).load_image("images/classificacaoIndicativa.png",0);	
	menu = (*ImageHandlerSDLObj).load_image("images/menu.png",0);
	mapa = (*ImageHandlerSDLObj).load_image("images/gamasoft_mapaTeste.png",0);


    font = TTF_OpenFont( "lazy.ttf", 28 );


	//depois colocar no quadro 1 (0) da fase 1 apos a abertura no switch
	initializeCenario1();

	(*timer).start();

	return 1;	//sucess
}


int finalize()
{
    //Free the surfaces
    SDL_FreeSurface( logoEmpresa );
    SDL_FreeSurface( logoJogo );
    SDL_FreeSurface(logoRecursos );
    SDL_FreeSurface( menu );
    SDL_FreeSurface( classificacaoIndicativa );
    SDL_FreeSurface( mapa );
	
		Mix_FreeMusic( music );
		Mix_FreeMusic( musicGame );
		Mix_FreeMusic( musicaAtual );

    SDL_FreeSurface( messageRecursos );	
	
    SDL_FreeSurface( messageUnidades );	
	
	/*
	//delete units
	if(unit1 != NULL)
		delete(unit1);
	if(unit2 != NULL)
		delete(unit2);
	*/

	//cenario
	finalizeCenario1();

	//delete other objects
	delete(ImageHandlerSDLObj);
	delete(drawObj);
	delete(randomObj);

	TTF_CloseFont( font );

	 //Free the music
    //Mix_FreeMusic( music );


    //Quit SDL_mixer
    Mix_CloseAudio();


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

void selecionarUnidadeNacao(Nacao nacao, int tileX, int tileY)
{
		for(list<Unidade *>::iterator it1 = nacao.exercito.begin(); it1 != nacao.exercito.end(); it1++) 
		{
			 //(*(*it1)).isDead = true;

			if(tileX == (*(*it1)).posX && tileY == (*(*it1)).posY)
			{
				if(unidadeSelecionada==0)
				{
					unidadeSelecionada = (*it1);
					
					if ((*(*it1)).isDead == false)
					{
						(*unidadeSelecionada).selecionado = true;	
					}			
				}					
				else
				{
					(*unidadeSelecionada).selecionado = false;					
					unidadeAlvo = (*it1);
					(*unidadeSelecionada).attack(unidadeAlvo);
					unidadeSelecionada = 0;					
					unidadeAlvo = 0;	
				}
			}
		}
}

void mostrandoUnidadesNacao(Nacao nacao)
{
	//Laço responsável por criar (show) todas as unidades criadas na Nacao
	for(list<Unidade *>::iterator it1 = nacao.exercito.begin(); it1 != nacao.exercito.end(); it1++)
	{
		if((*it1) != NULL && !(*(*it1)).isDead)
		(*(*it1)).show(); 
	}
}

		
int get_inputs()
{
	
    while( SDL_PollEvent( &event ) )
    {
		if( event.type == SDL_KEYDOWN )
		{
			if( event.key.keysym.sym == SDLK_ESCAPE ) 
				quit = true;
	

			/*
			//Remover última unidade adicionada na lista: Vai ser útil quando implementarmos o ataque corretamente
			if(event.key.keysym.sym == SDLK_3 && unidadeSelecionada != 0)
				(*unidadeSelecionada).isDead = true;
			*/

			if(unidadeSelecionada != 0)
			{
				if( event.key.keysym.sym == SDLK_a )
				{ 	
			
					if((*unidadeSelecionada).qtdMovimentos>0)
					{
						(*unidadeSelecionada).posX -= 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}	
												
			
				}

				if( event.key.keysym.sym == SDLK_d ) 
				{	
					if((*unidadeSelecionada).qtdMovimentos>0)
					{
						(*unidadeSelecionada).posX += 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}	
				}				
			
				if( event.key.keysym.sym == SDLK_w ) 
				{
					if((*unidadeSelecionada).qtdMovimentos>0)
					{
						(*unidadeSelecionada).posY -= 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}
				}
				
				if( event.key.keysym.sym == SDLK_s ) 
				{
					if((*unidadeSelecionada).qtdMovimentos>0)
					{
						(*unidadeSelecionada).posY += 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}	
				}
			}

			//alternando modo do mapa
			if(event.key.keysym.sym == SDLK_0)
			{
				modo++;
				modo = modo % 4;		//4 modos
			}
			
			if(event.key.keysym.sym == SDLK_8)
			{
				for(list<Unidade *>::iterator it1 = (*nacao2).exercito.begin(); it1 != (*nacao2).exercito.end(); it1++)
				{
					if((*(*it1)).tipo == SOLDADO)
					(*(*it1)).qtdMovimentos = 5; 

					else if((*(*it1)).tipo == NAVIO)
					(*(*it1)).qtdMovimentos = 3; 
					
				}

				nacaoSelecionada = nacao1;
			}

			if(event.key.keysym.sym == SDLK_9)
			{
				for(list<Unidade *>::iterator it1 = (*nacao1).exercito.begin(); it1 != (*nacao1).exercito.end(); it1++)
				{
					if((*(*it1)).tipo == SOLDADO)
					(*(*it1)).qtdMovimentos = 5; 

					else if((*(*it1)).tipo == NAVIO)
					(*(*it1)).qtdMovimentos = 3; 
				}
				nacaoSelecionada = nacao2;
			}

			if(event.key.keysym.sym == SDLK_1)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,SOLDADO,10,nacaoSelecionada,5));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			if(event.key.keysym.sym == SDLK_2)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,NAVIO,10,nacaoSelecionada,3));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			/*

			if(event.key.keysym.sym == SDLK_3)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,CANHAO,10,nacaoSelecionada));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			if(event.key.keysym.sym == SDLK_4)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,AVIAO,10,nacaoSelecionada));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}
			*/
		}
		

		if(event.type == SDL_MOUSEBUTTONUP)
		{
			int X = event.button.x;
			int Y = event.button.y;

			int tileX = X/30;
			int tileY = Y/30;

			//unidadeSelecionada
			if(nacaoSelecionada == nacao1 || unidadeSelecionada != 0)
			selecionarUnidadeNacao((*nacao1), tileX, tileY);

			if(nacaoSelecionada == nacao2 || unidadeSelecionada != 0)			
			selecionarUnidadeNacao((*nacao2), tileX, tileY);
		
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
					(*drawObj).apply_surface( 200, 100, logoEmpresa, screen,0);
					SDL_Delay(2000);
					break;

			case 3:
					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( 200, 0, logoRecursos, screen,0);
					SDL_Delay(2000);			
					break;
			case 4:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( 0, 0, classificacaoIndicativa, screen,0);
					SDL_Delay(2000);
					break;
					
			case 6:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( 0, 0, menu, screen,0);
					musica = MENU;
					playMusic();
					              

					SDL_Delay(2000);				//trabalhando com esse para esta entrega
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

int playMusic(){
	Mix_HaltMusic();	
	musicaAtual = NULL;
	 if(musica == MENU){
	 	musicaAtual = music;

	 }else{
	 	if(musica == JOGO){
	 		musicaAtual = musicGame;
	 	}

	 }

	if( Mix_PlayingMusic() == 0 )
	{ 
		//Play the music
		if( Mix_PlayMusic( musicaAtual, -1 ) == -1 )
		{
			return 1;
		}
	}
	//If music is being played
	else
	{
		//If the music is paused
		if( Mix_PausedMusic() == 1 )
		{
		//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}     
		 	return 1; 
}

int do_drawing()
{
	//comecando do inicio do jogo
	//scenarioAtual=INICIO;

	if(scenarioAtual==TELA_INICIAL)
	{
		switch(quadroEstado)			//switch para diferenciar parte da animacao por quadro
		{
			case 1:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( 200, 100, logoEmpresa, screen,0);
					break;

			case 2:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( 50, 0, logoRecursos, screen,0);
					break;
			
			case 3:
					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( 0, 0, classificacaoIndicativa, screen,0);
					break;

			case 4:
			default:
					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( 0, 0, menu, screen,0);
					selecionarMenu();
					
					
					break;
		}
	}

	/*
	else 
		scenarioAtual=INICIO;
	*/

	if(scenarioAtual==INICIO)
	{


		//limpando tela anterior colocando a cor branca no lugar
		SDL_FillRect(screen, NULL, 0xFFFFFF);	

		//(*cenario).show();

		//desenhando mapa de bits de acordo ao modo
		if(modo == MODO_NORMAL) {
			(*drawObj).apply_surface( 0, 0, mapa, screen,0);

					musica = JOGO;
					playMusic();
		}
		else{
			for(int i = 0; i < (*cenario).numeroTilesY; i++)
			{
				for(int j = 0; j < (*cenario).numeroTilesX; j++)
				{
					rect.x = j*30;
					rect.y = i*30;
					rect.w = 30;
					rect.h = 30;
				
					switch(modo)
					{
					 		case MODO_QUADRADOS_PREENCHIDOS:
								SDL_FillRect(screen, &rect, cores[(*cenario).tiles[i][j] -> tipo]);
							break;
							// case MODO_QUADRADOS:
							// 	(*drawObj).drawRect(screen, rect.x, rect.y, rect.w, rect.h, cores[(*cenario).tiles[i][j] -> tipo]);
							// break;
							// case MODO_CIRCULOS:
							// 	(*drawObj).drawCircle(screen, rect.x, rect.y, rect.w/2, cores[(*cenario).tiles[i][j] -> tipo], false);
							// break;
					}
				}
			}
		}
		

		mostrandoUnidadesNacao((*nacao1));
		mostrandoUnidadesNacao((*nacao2));

		(*nacaoSelecionada).carregaScore();

		(*drawObj).apply_surface( 0, 0, messageRecursos, screen, 0 );
		
		(*drawObj).apply_surface( 0, 40, messageUnidades, screen, 0 );	
	}
		


	if( SDL_Flip( screen ) == -1 )
	{
		cout << "Nao conseguiu realizar a funcao SDL_Flip" << endl;
	    return -1;
	}

    frame++;

    //If a second has passed since the caption was last updated
	if( (*timer).get_ticks() < 1000 / FRAMES_PER_SECOND )
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - (*timer).get_ticks() );
    }

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




