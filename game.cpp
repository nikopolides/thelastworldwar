#include "game.h"
#include "globalsGame.h" 
#include "Nacao.h"
#include "Unidade.h"
#include "Territorio.h"
#include "SDL/SDL_ttf.h"

#define AVIAO 0
#define NAVIO 1
#define SOLDADO 2
#define CANHAO 3

int height = 0;
int width = 0;

Nacao* nacao1 = new Nacao(800,800,800,800,"Estados Unidos");
Nacao* nacao2 = new Nacao(800,800,800,800,"Siria");
Territorio* territorioEua = new Territorio();
Territorio* territorioSiria = new Territorio();
Nacao* nacaoSelecionada = nacao1;

Unidade* unidadeSelecionada = NULL;
Unidade* unidadeAlvo = NULL;



Mix_Music *music = NULL;

int sound()
{

	return 1;	
}


//Funcao Menu
void selecionarMenu(){

	if(event.type == SDL_MOUSEBUTTONUP) 
	{
			
		int tileX = event.button.x;
		int tileY = event.button.y;

	
	
		//Abrir jogo
		if( (tileX>= (height + 300 )&& tileX<=(height + 570)) && (tileY>=(width + 300) && tileY<= (width+390)) ){
			
			scenarioAtual=PREPARACAOJOGO;	

		}
		
		//Instrucoes
		if( (tileX>=10 && tileX<=19) && (tileY>=14 && tileY<=17) ){
			
			scenarioAtual=INSTRUCOESCENA;	

		}
		//opcoes
		if( (tileX>=10 && tileX<=19) && (tileY>=18 && tileY<=20) ){
			
			scenarioAtual=OPCOES;	

		}

		//Sair	
		if( (tileX>=10 && tileX<=19) && (tileY>=21 && tileY<=24) ) {
			quit = true;
	
		}


		//creditos
		if( (tileX>=10 && tileX<=19) && (tileY>=25 && tileY<=27) ){
			
			scenarioAtual=CREDITOS;	
		}

	}
}

// //diferentes cenarios
// int initializeCenario1()
// {
// 	(*nacao1).exercitoAdd(new Unidade(3,3,SOLDADO,10,nacao1,5));
// 	(*nacao1).exercitoAdd(new Unidade(5,2,NAVIO,10,nacao1,3));	
// 	(*nacao1).exercitoAdd(new Unidade(6,7,AVIAO,10,nacao1,10));	
// 	(*nacao1).exercitoAdd(new Unidade(4,5,CANHAO,10,nacao1,5));

// 	(*nacao2).exercitoAdd(new Unidade(24,16,SOLDADO,10,nacao2,5));
// 	(*nacao2).exercitoAdd(new Unidade(20,18,NAVIO,10,nacao2,3));	
// 	(*nacao2).exercitoAdd(new Unidade(22,18,AVIAO,10,nacao2,10));	
// 	(*nacao2).exercitoAdd(new Unidade(18,18,CANHAO,10,nacao2,5));	
// }

void selecionaNacao(){


if(event.type == SDL_MOUSEBUTTONUP) 
	{
			
		int X = event.button.x;
		int Y = event.button.y;

		int tileX = X/30;
		int tileY = Y/30;

	
		//EUA
		if( (tileX>=6 && tileX<=15) && (tileY>=12 && tileY<=14) ){
			//Escolheu EUA... Definir como fazer essa definicao
		
			scenarioAtual=NIVEL;
		}
			
		//Siria	
		if( (tileX>=26 && tileX<=35) && (tileY>=12 && tileY<=14) ) {
			//Escolheu sIRIA... Definir como fazer essa definicao
		
			scenarioAtual=NIVEL;		
	
		}

		//Voltar
		if( (tileX>=1 && tileX<=10) && (tileY>=20 && tileY<=22) ) {
		
			scenarioAtual=MENU_INICIAL;
	
		}
	}

}

void selecionarNivel(){

	if(event.type == SDL_MOUSEBUTTONUP) 
		{
				
			int X = event.button.x;
			int Y = event.button.y;

			int tileX = X/30;
			int tileY = Y/30;

		
			//Nivel 1
			if( (tileX>=15 && tileX<=24) && (tileY>=8 && tileY<=11) ){
				//Escolheu Nivel 1... Definir como fazer essa definicao
			
				scenarioAtual=LOADING;
			}
				
			//Nivel 2
			if( (tileX>=15 && tileX<=24) && (tileY>=12 && tileY<=14) ) {
				//Escolheu NIvel 2... Definir como fazer essa definicao
			
				scenarioAtual=LOADING;		
		
			}

			//Nivel 3
			if( (tileX>=15 && tileX<=24) && (tileY>=15 && tileY<=18) ) {
			//Escolheu NIvel 2... Definir como fazer essa definicao
				scenarioAtual=LOADING;
		
			}

			//Nivel 4
			if( (tileX>=15 && tileX<=24) && (tileY>=19 && tileY<=22) ) {
			//Escolheu NIvel 3... Definir como fazer essa definicao
				scenarioAtual=LOADING;
		
			}
			
			//Nivel 5
			if( (tileX>=15 && tileX<=24) && (tileY>=23 && tileY<=25) ) {
			//Escolheu NIvel 2... Definir como fazer essa definicao
				scenarioAtual=LOADING;
		
			}

			//Voltar
			if( (tileX>=1 && tileX<=10) && (tileY>=24 && tileY<=26) ) {
			
				scenarioAtual=MENU_INICIAL;
		
			}
			
			

		}
}

void selecionarOpcoes(){
	if(event.type == SDL_MOUSEBUTTONUP) 
		{
				
			int X = event.button.x;
			int Y = event.button.y;

			int tileX = X/30;
			int tileY = Y/30;

		
			//Aumentar SoundTrack
			if( (tileX>=15 && tileX<=24) && (tileY>=8 && tileY<=11) ){
				//Escolheu Nivel 1... Definir como fazer essa definicao
			
				printf("AUmentar Sound Track\n");
			}
				
			//Diminuir SoundTrack
			if( (tileX>=15 && tileX<=24) && (tileY>=12 && tileY<=14) ) {
				//Escolheu NIvel 2... Definir como fazer essa definicao
			
				printf("DIminuir SoundTrACK\n");	
		
			}

			//Aumentar Sound Effect
			if( (tileX>=15 && tileX<=24) && (tileY>=15 && tileY<=18) ) {
			//Escolheu NIvel 2... Definir como fazer essa definicao
				printf("aUMENTAR SoundEFFECT\n");	
		
			}

			//Diminuir Sound Effect
			if( (tileX>=15 && tileX<=24) && (tileY>=19 && tileY<=22) ) {
			//Escolheu NIvel 3... Definir como fazer essa definicao
					printf("DIminuir SoundEFFECT\n");	
		
			}

			//Voltar
			if( (tileX>=1 && tileX<=10) && (tileY>=24 && tileY<=26) ) {
			
				scenarioAtual=MENU_INICIAL;
		
			}
			
			

		}
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
	const int SCREEN_WIDTH = 1980;
	const int SCREEN_HEIGHT = 1024 ;
	const int SCREEN_BPP = 32;

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
	escolhaNacao = (*ImageHandlerSDLObj).load_image("images/telaNacao.png", 0);
	nivel = (*ImageHandlerSDLObj).load_image("images/telaNivel.png", 0);
  	telaInstrucoes = (*ImageHandlerSDLObj).load_image("images/telaInstrucoes.png", 0);
  	telaOpcoes = (*ImageHandlerSDLObj).load_image("images/telaOpcoes.png", 0);
  	telaCreditos = (*ImageHandlerSDLObj).load_image("images/telaCreditos.png", 0);
  	telaLoading = (*ImageHandlerSDLObj).load_image("images/telaLoading.png", 0);
  	loading = (*ImageHandlerSDLObj).load_image("images/loadingPiece.png", 0);
    font = TTF_OpenFont( "lazy.ttf", 28 );
    fontMenu = TTF_OpenFont( "lazy.ttf", 40);

    TTF_SetFontStyle(fontMenu, TTF_STYLE_BOLD);

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
    SDL_FreeSurface( escolhaNacao );
    SDL_FreeSurface( nivel );
    SDL_FreeSurface( telaInstrucoes );
    SDL_FreeSurface( telaOpcoes );
    SDL_FreeSurface( telaCreditos );
    SDL_FreeSurface( telaLoading );
    SDL_FreeSurface( loading );
	
	Mix_FreeMusic( music );

    SDL_FreeSurface( messageRecursos );	
    SDL_FreeSurface( messageUnidades );	
	SDL_FreeSurface( opcaoJogar );	
	SDL_FreeSurface( opcaoInstrucoes );	
	SDL_FreeSurface( opcaoOpcoes );	
	SDL_FreeSurface( opcaoSair );	
    SDL_FreeSurface( opcaoCreditos );	
    SDL_FreeSurface( textoCompleto );
    SDL_FreeSurface( creditosCompleto );
    SDL_FreeSurface( textoAudio );
    SDL_FreeSurface( textoSoundT );
    SDL_FreeSurface( textoSoundE );    

    SDL_FreeSurface( timeEua );	
	SDL_FreeSurface( timeSiria );	
    SDL_FreeSurface( opcaoVoltar );

    SDL_FreeSurface( opcaoNivel1 );
    SDL_FreeSurface( opcaoNivel2 );
    SDL_FreeSurface( opcaoNivel3 );
    SDL_FreeSurface( opcaoNivel4 );
    SDL_FreeSurface( opcaoNivel5 );
	
	//cenario
	finalizeCenario1();

	//delete other objects
	delete(ImageHandlerSDLObj);
	delete(drawObj);
	delete(randomObj);

	TTF_CloseFont( font );
	TTF_CloseFont( fontMenu);

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
			
					if((*unidadeSelecionada).qtdMovimentos>0 && (*unidadeSelecionada).canMove((*cenario).tiles[(*unidadeSelecionada).posX-1][(*unidadeSelecionada).posY]))
					{
						(*unidadeSelecionada).posX -= 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}	
				}

				if( event.key.keysym.sym == SDLK_d ) 
				{	
					if((*unidadeSelecionada).qtdMovimentos>0 && (*unidadeSelecionada).canMove((*cenario).tiles[(*unidadeSelecionada).posX+1][(*unidadeSelecionada).posY]))
					{
						(*unidadeSelecionada).posX += 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}	
				}				
			
				if( event.key.keysym.sym == SDLK_w ) 
				{
					if((*unidadeSelecionada).qtdMovimentos>0 && (*unidadeSelecionada).canMove((*cenario).tiles[(*unidadeSelecionada).posX][(*unidadeSelecionada).posY-1]))
					{
						(*unidadeSelecionada).posY -= 1;							
						(*unidadeSelecionada).qtdMovimentos--;					
					}
				}
				
				if( event.key.keysym.sym == SDLK_s ) 
				{
					if((*unidadeSelecionada).qtdMovimentos>0 && (*unidadeSelecionada).canMove((*cenario).tiles[(*unidadeSelecionada).posX][(*unidadeSelecionada).posY+1]))
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
				(*territorioEua).coletar();
				for(list<Unidade *>::iterator it1 = (*nacao2).exercito.begin(); it1 != (*nacao2).exercito.end(); it1++)
				{
					if((*(*it1)).tipo == SOLDADO)
					(*(*it1)).qtdMovimentos = 5; 

					else if((*(*it1)).tipo == NAVIO)
					(*(*it1)).qtdMovimentos = 3; 
					
					else if((*(*it1)).tipo == AVIAO)
					(*(*it1)).qtdMovimentos = 10; 

					else if((*(*it1)).tipo == CANHAO)
					(*(*it1)).qtdMovimentos = 5; 	
				}

				nacaoSelecionada = nacao1;
			}

			if(event.key.keysym.sym == SDLK_9)
			{
				(*territorioSiria).coletar();
				for(list<Unidade *>::iterator it1 = (*nacao1).exercito.begin(); it1 != (*nacao1).exercito.end(); it1++)
				{
					if((*(*it1)).tipo == SOLDADO)
					(*(*it1)).qtdMovimentos = 5; 

					if((*(*it1)).tipo == NAVIO)
					(*(*it1)).qtdMovimentos = 3; 
								
					if((*(*it1)).tipo == AVIAO)
					(*(*it1)).qtdMovimentos = 10; 

					if((*(*it1)).tipo == CANHAO)
					(*(*it1)).qtdMovimentos = 5;
				}
				nacaoSelecionada = nacao2;
			}

			if(event.key.keysym.sym == SDLK_1)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,SOLDADO,10,nacaoSelecionada,5,1));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			if(event.key.keysym.sym == SDLK_2)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,NAVIO,10,nacaoSelecionada,3,2));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			if(event.key.keysym.sym == SDLK_3)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,CANHAO,10,nacaoSelecionada,5,1));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}

			if(event.key.keysym.sym == SDLK_4)
			{
				(*nacaoSelecionada).exercitoAdd(new Unidade(1,1,AVIAO,10,nacaoSelecionada,10,3));
				mostrandoUnidadesNacao((*nacaoSelecionada));
			}
			
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
					(*drawObj).apply_surface( height + 200,  width + 100, logoEmpresa, screen,0);
					SDL_Delay(2000);
					break;

			case 3:
					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height + 200,width, logoRecursos, screen,0);
					SDL_Delay(2000);			
					break;
			case 4:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( height, width, classificacaoIndicativa, screen,0);
					SDL_Delay(2000);
					break;
					
			case 6:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( height,width, menu, screen,0);
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
	
	music = Mix_LoadMUS( "soundtrack/musica2.ogg" );
	

	if( Mix_PlayingMusic() == 0 )
	{ 
		//Play the music
		if( Mix_PlayMusic( music, -1 ) == -1 )
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

int playMusicGame(){
	
	Mix_HaltMusic();

	
		music = Mix_LoadMUS( "soundtrack/musica3.ogg" );
	

	if( Mix_PlayingMusic() == 0 )
	{ 
		//Play the music
		if( Mix_PlayMusic( music, -1 ) == -1 )
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
	//Telas de apresentacao
	if(scenarioAtual==TELA_INICIAL)
	{	

		switch(quadroEstado)			//switch para diferenciar parte da animacao por quadro
		{
			case 1:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( height, width, logoEmpresa, screen,0);
					break;

			case 2:
					SDL_FillRect(screen, NULL, 0xFFFFFF);
					(*drawObj).apply_surface( height + 50, width , logoRecursos, screen,0);
					break;
			
			case 3:
					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height , width, classificacaoIndicativa, screen,0);
					break;

			case 4:
			default:			
					scenarioAtual = MENU_INICIAL;
					
					break;
		}
	}


	//Menu Principal!!
	if(scenarioAtual==MENU_INICIAL){
					
		

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height, width, menu, screen,0);
					

					SDL_Color textColor = {0, 0, 0, 0};
					sprintf(jogar,"Jogar");
					sprintf(instrucoes,"Instruções");
					sprintf(opcoes,"Opções");
					sprintf(sair,"Sair");
					sprintf(creditos,"Créditos");
	
					opcaoJogar = TTF_RenderText_Solid( fontMenu, jogar,textColor );
					opcaoInstrucoes = TTF_RenderUTF8_Solid( fontMenu, instrucoes,textColor );
					opcaoOpcoes = TTF_RenderUTF8_Solid( fontMenu, opcoes,textColor );
					opcaoSair = TTF_RenderUTF8_Solid( fontMenu, sair,textColor );
					opcaoCreditos = TTF_RenderUTF8_Solid( fontMenu, creditos,textColor );

					(*drawObj).apply_surface( height + 400, width + 330, opcaoJogar, screen, 0 );
					(*drawObj).apply_surface( height + 330, width + 440, opcaoInstrucoes, screen, 0 );
					(*drawObj).apply_surface( height + 380, width + 550, opcaoOpcoes, screen, 0 );
					(*drawObj).apply_surface( height + 400, width + 660, opcaoSair, screen, 0 );
					(*drawObj).apply_surface( height + 350, width + 770, opcaoCreditos, screen, 0 );

					
				
					selecionarMenu();

		}

	
  //Telas Instrucoes
	if (scenarioAtual==INSTRUCOESCENA){

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( 0, 0, telaInstrucoes, screen,0);
					

					//SDL_Color textColor = {0, 0, 0, 0};
					SDL_Color textColor = {255, 255, 255, 255};
					sprintf(instrucoes,"Instruções");
					sprintf(texto,"Escrever o jeito de jogar, com os diferentes de níveis.");
					sprintf(voltar,"Voltar");
					
					opcaoInstrucoes = TTF_RenderUTF8_Solid( fontMenu, instrucoes,textColor );
					textoCompleto = TTF_RenderUTF8_Solid( fontMenu, texto,textColor );
					opcaoVoltar = TTF_RenderUTF8_Solid( fontMenu, voltar,textColor );

					(*drawObj).apply_surface( height +  520, width +  290, opcaoInstrucoes, screen, 0 );
					(*drawObj).apply_surface( height +  520, width +  390, textoCompleto, screen, 0 );
					(*drawObj).apply_surface( height +  100, width +  630, opcaoVoltar, screen, 0 );
					//COlocar opcao de voltarp ara o menu principal
	}
	//Telas Opcoes
	if (scenarioAtual==OPCOES){

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height, width, telaOpcoes, screen,0);
					

					//SDL_Color textColor = {0, 0, 0, 0};
					SDL_Color textColor = {255, 255, 255, 255};
					sprintf(audio,"Áudio");
					sprintf(soundT,"SoundTrack");
					sprintf(soundE,"Sound Effects");
					sprintf(voltar,"Voltar");

					textoAudio = TTF_RenderUTF8_Solid( fontMenu, audio,textColor );
					textoSoundT = TTF_RenderUTF8_Solid( font, soundT,textColor );
					textoSoundE = TTF_RenderUTF8_Solid( font, soundE,textColor );
					opcaoVoltar = TTF_RenderUTF8_Solid( fontMenu, voltar,textColor );

					(*drawObj).apply_surface( height +  520, width +  250, textoAudio, screen, 0 );
					(*drawObj).apply_surface( height +  300, width +  350, textoSoundT, screen, 0 );
					(*drawObj).apply_surface( height +  300, width +  450, textoSoundE, screen, 0 );
					(*drawObj).apply_surface( height +  100, width +  750, opcaoVoltar, screen, 0 );
					//COlocar opcao de voltarp ara o menu principal

					selecionarOpcoes();

	}

	if(scenarioAtual==CREDITOS){

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height, width, telaCreditos, screen,0);
					

					SDL_Color textColor = {255, 255, 255, 255};
					sprintf(creditosTexto,"Programadores: Fernando Paixão, Gabriela Navarro, Matheus Tristão Artistas: Gabriela Navarro e Victor Navarro");
					sprintf(voltar,"Voltar");
	
					creditosCompleto = TTF_RenderUTF8_Solid( font, creditosTexto,textColor );
					opcaoVoltar = TTF_RenderUTF8_Solid( fontMenu, voltar,textColor );

					(*drawObj).apply_surface( height +  400, width +  330, creditosCompleto, screen, 0 );


					if(event.type == SDL_MOUSEBUTTONUP) 
						
						{
								
							int X = event.button.x;
							int Y = event.button.y;

							int tileX = X/30;
							int tileY = Y/30;

							//Voltar
							if( (tileX>=1 && tileX<=10) && (tileY>=20 && tileY<=22) ) {
							
								scenarioAtual=MENU_INICIAL;
						
							}
						}
					
	}

	//Ecolha da nacao
	if(scenarioAtual==PREPARACAOJOGO)
	{

		SDL_FillRect(screen, NULL, 0x000000);
		(*drawObj).apply_surface( height, width, escolhaNacao, screen,0);

			SDL_Color textColor = {0, 0, 0, 0};
			sprintf(eua,"EUA");
			sprintf(siria,"Síria");
			sprintf(voltar,"Voltar");
			

			timeEua = TTF_RenderText_Solid( fontMenu, eua,textColor );
			timeSiria = TTF_RenderUTF8_Solid( fontMenu, siria,textColor );
			opcaoVoltar = TTF_RenderUTF8_Solid( fontMenu, voltar,textColor );
			
			(*drawObj).apply_surface( height +  310, width +  390, timeEua, screen, 0 );
			(*drawObj).apply_surface( height +  900, width +  380, timeSiria, screen, 0 );
			(*drawObj).apply_surface( height +  100, width +  630, opcaoVoltar, screen, 0 );

			selecionaNacao();
	}

	//Escolha do nivel
	if (scenarioAtual==NIVEL){

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height, width, nivel, screen,0);
					

					SDL_Color textColor = {0, 0, 0, 0};

					sprintf(nivel1,"Nível 1");
					sprintf(nivel2,"Nível 2");
					sprintf(nivel3,"Nível 3");
					sprintf(nivel4,"Nível 4");
					sprintf(nivel5,"Nível 5");
					sprintf(voltar,"Voltar");
	
					opcaoNivel1 = TTF_RenderUTF8_Solid( fontMenu, nivel1,textColor );
					opcaoNivel2 = TTF_RenderUTF8_Solid( fontMenu, nivel2,textColor );
					opcaoNivel3 = TTF_RenderUTF8_Solid( fontMenu, nivel3,textColor );
					opcaoNivel4 = TTF_RenderUTF8_Solid( fontMenu, nivel4,textColor );
					opcaoNivel5 = TTF_RenderUTF8_Solid( fontMenu, nivel5,textColor );
					opcaoVoltar = TTF_RenderUTF8_Solid( fontMenu, voltar,textColor );

					(*drawObj).apply_surface( height +  520, width +  290, opcaoNivel1, screen, 0 );
					(*drawObj).apply_surface( height +  520, width +  390, opcaoNivel2, screen, 0 );
					(*drawObj).apply_surface( height +  520, width +  500, opcaoNivel3, screen, 0 );
					(*drawObj).apply_surface( height +  520, width +  610, opcaoNivel4, screen, 0 );
					(*drawObj).apply_surface( height +  520, width +  720, opcaoNivel5, screen, 0 );
					(*drawObj).apply_surface( height +  80, width +  750, opcaoVoltar, screen, 0 );
					
					selecionarNivel();
	}

	//Telas Loading
	if (scenarioAtual==LOADING){

					SDL_FillRect(screen, NULL, 0x000000);
					(*drawObj).apply_surface( height, width, telaLoading, screen,0);

					carregarLoading();
					
	}
	//Inicio do jogo
	if(scenarioAtual==INICIO)
	{

		//limpando tela anterior colocando a cor branca no lugar
		SDL_FillRect(screen, NULL, 0xFFFFFF);	


		//desenhando mapa de bits de acordo ao modo
		if(modo == MODO_NORMAL) {
			(*drawObj).apply_surface( height, width, mapa, screen,0);

			/*for(int i = 0; i < (*cenario).numeroTilesY; i++)
			{
				for(int j = 0; j < (*cenario).numeroTilesX; j++)
				{								
					(*(*cenario).tiles[i][j]).show();
				}
			}*/
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

					}
				}
			}
		}
		

		mostrandoUnidadesNacao((*nacao1));
		mostrandoUnidadesNacao((*nacao2));

		(*nacaoSelecionada).carregaScore();

		(*drawObj).apply_surface( height, width, messageRecursos, screen, 0 );
		
		(*drawObj).apply_surface( height, width + 40, messageUnidades, screen, 0 );	
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


//diferentes cenarios
int initializeCenario1()
{
	(*territorioEua).conquistar(nacao1);
	(*territorioSiria).conquistar(nacao2);

	std::thread first (playMusic);
	first.join();

	(*nacao1).exercitoAdd(new Unidade(3,3,SOLDADO,10,nacao1,5,1));
	(*nacao1).exercitoAdd(new Unidade(5,2,NAVIO,10,nacao1,3,2));	
	(*nacao1).exercitoAdd(new Unidade(6,7,AVIAO,10,nacao1,10,3));	
	(*nacao1).exercitoAdd(new Unidade(4,5,CANHAO,10,nacao1,5,1));

	(*nacao2).exercitoAdd(new Unidade(24,16,SOLDADO,10,nacao2,5,1));
	(*nacao2).exercitoAdd(new Unidade(20,18,NAVIO,10,nacao2,3,2));	
	(*nacao2).exercitoAdd(new Unidade(22,18,AVIAO,10,nacao2,10,3));	
	(*nacao2).exercitoAdd(new Unidade(18,18,CANHAO,10,nacao2,5,1));	

	const int LINHAS_MAPA = 24;
	const int COLUNAS_MAPA = 33;

	int **mapaMundi = (int**)calloc(LINHAS_MAPA*COLUNAS_MAPA, sizeof(int*));
	for(int i = 0; i<LINHAS_MAPA; i++)
	{
		mapaMundi[i] = (int*)calloc(COLUNAS_MAPA, sizeof(int));
	}

	//criando a variavel auxiliar apenas para aproveitar esta forma de declaracao de array com chaves, carregar de arquivo depois
	int auxMapaMundi[LINHAS_MAPA][COLUNAS_MAPA] = 
			   {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 1, 1, 1, 1, 1, 1, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
				{0, 0, 1, 1, 1, 3, 1, 2, 1, 0, 5, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
				{0, 0, 1, 1, 1, 3, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
				{0, 0, 1, 1, 6, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
				{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 5, 1, 3, 1, 0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 5, 0},
				{0, 0, 0, 0, 1, 1, 1, 5, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 1, 1, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 2, 1, 1, 0, 0},
				{0, 0, 0, 0, 0, 1, 1, 1, 2, 6, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 6, 1, 0, 0, 0},
				{0, 0, 0, 5, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 1, 6, 3, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 3, 6, 1, 0, 0, 5, 0, 1, 0, 1, 6, 1, 0},
				{0, 0, 0, 0, 0, 1, 6, 1, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 1, 3, 1, 5},
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 5, 0, 1, 1, 1, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 1, 1, 2, 6, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 1, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	
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

	(*territorioEua).addTile((*cenario).tiles[2][2]);
	(*territorioSiria).addTile((*cenario).tiles[20][6]);

	return 1;
}

void carregarLoading(){
					int i = 0;
					int x = 300;
					int y = 432;
				//SUBSTITUIR POR Thread para carregar imagem do Loading:
					for(i=0; i<13 ; i++)
					{
						(*drawObj).apply_surface( x, y, loading, screen,0);

						x+= 30;
						if(i==13){
							scenarioAtual=INICIO;
						}
						
						if( event.type == SDL_KEYDOWN )
								{
									if(event.key.keysym.sym == SDLK_i)
										{
										Mix_HaltMusic();
					std::thread second (playMusicGame);
					second.join();
										scenarioAtual=INICIO;
										}
								}
					}
}

int finalizeCenario1()
{
	(*cenario).finalize();
	delete(cenario);

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




