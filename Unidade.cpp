#include "Unidade.h"
#include "Nacao.h"
#include "Tile.h"


enum {
	AVIAO,
	NAVIO,
	SOLDADO,
	CANHAO
};

	int lastTime = SDL_GetTicks();
	int animationRate = 12;
    int animationLength = 13;


Unidade::Unidade(int _posX, int _posY, int _tipo, int _forca, Nacao* _nacao, int _qtdMovimentos, int _ambiente) 
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;
	forca = _forca;
	isDead = false;
	nacao = _nacao;
	selecionado = false;
	qtdMovimentos = _qtdMovimentos;
	ambiente = _ambiente;
}
int Unidade::show()
{
	if(tipo == SOLDADO)
	{
		  if (((SDL_GetTicks() - lastTime) * animationRate / 1000) % animationLength ==0) 
    	  {	
			rect.x = 30*0+1;
			rect.y = 30*0+1;		
		}				
		else if (((SDL_GetTicks() - lastTime) * animationRate / 1000) % animationLength !=0) 
		{
			rect.x = 30*1+1;
			rect.y = 30*0+1;
		} 
	 } 
	

	if (tipo == NAVIO)
	{
		rect.x = 30*0;
		rect.y = 32*4+3;
	}
	
	if (tipo == CANHAO)
	{
		rect.x = 33*5;
		rect.y = 30*1+3;
	}

	if (tipo == AVIAO)
	{
		rect.x = 32*8+4;
		rect.y = 32*4+3;
	}

	if(modo != MODO_NORMAL)
	{
		rect.x = posX*30;
		rect.y = posY*30;
	}

	rect.w = 30;
	rect.h = 30;	

	switch(modo)
	{
		case MODO_NORMAL:
			if(selecionado)
				SDL_SetAlpha(civilizationUnits, SDL_SRCALPHA, 100);
			(*drawObj).apply_surface( posX*30, posY*30, civilizationUnits, screen, &rect);
			//SDL_FillRect(screen, &rect, 0x000000AA);
			SDL_SetAlpha(civilizationUnits, SDL_SRCALPHA, 255);
			break;
		case MODO_QUADRADOS_PREENCHIDOS:
			SDL_FillRect(screen, &rect, cores[PRETO]);
			break;
		// case MODO_QUADRADOS:
		// 	(*drawObj).drawRect(screen, rect.x, rect.y, rect.w, rect.h, cores[PRETO]);
		// 	break;
		// case MODO_CIRCULOS:
		// 	(*drawObj).drawCircle(screen, rect.x, rect.y, rect.w/2, cores[PRETO],false);
		// 	break;
	}

	return 1;
}

int Unidade::attack(Unidade * inimigo)
{
	if( nacao == (*inimigo).nacao)
	{
		//printf("Nao pode atacar alguem da mesma nacao\n\n");
		return 1;
	}	


	//80% da forca mais 20% da forca vezes um numero aleatorio de 1 a 10
	int ataque = 0.8 * forca 			+ 0.2 * forca * (*randomObj).gerarNumero(10);
	int defesa = 0.8 * (*inimigo).forca + 0.2 * (*inimigo).forca * (*randomObj).gerarNumero(10);

	if(ataque > defesa)
	{
		(* inimigo).isDead = true;		
		(*(* inimigo).nacao).contarExercito();	
	}
	else
	{
		isDead = true;
		(*nacao).contarExercito();
	}

	return 1;
}

bool Unidade::canMove(Tile* tileDestino)
{
/*	cout << ambiente << " " << (*tileDestino).tipo << endl;
	cout << ((*tileDestino).tipo != OCEANO) << endl;
	cout << ((*tileDestino).tipo != PETROLEO) << endl;
	cout << (ambiente == TERRESTRE) << endl;*/

	if( (*tileDestino).ocupante != NULL )
	{
		if( nacao != (*(*tileDestino).ocupante).nacao )
			attack( (*tileDestino).ocupante );

		if( (*(*tileDestino).ocupante).isDead )
			(*tileDestino).ocupante = NULL;

		return false;
	}

	if( (*tileDestino).tipo == QUALQUER_AMBIENTE )				//qualquer ambiente AVIAO
		return true;
	if( ambiente == TERRESTRE )
	{
		if( (*tileDestino).tipo != OCEANO && (*tileDestino).tipo != PETROLEO )
			return true;
	}
	if( ambiente == AQUATICO )
	{
		if( (*tileDestino).tipo == OCEANO || (*tileDestino).tipo == PETROLEO )
			return true;
	}

	return false;
}


