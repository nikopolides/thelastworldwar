#include "Unidade.h"

enum {
	AVIAO,
	NAVIO,
	SOLDADO,
	CANHAO
};

Unidade::Unidade(int _posX, int _posY, int _tipo, int _forca, string nacao)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;
	forca = _forca;
	isDead = false;
	nacao = nacao;
}
int Unidade::show()
{
	if(tipo == SOLDADO)
	{
		rect.x = 30*0;
		rect.y = 30*0;
	}
	if (tipo == NAVIO)
	{
		rect.x = 30*0;
		rect.y = 32*4+1;
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
			(*drawObj).apply_surface( posX*30, posY*30, civilizationUnits, screen, &rect);
			break;
		case MODO_QUADRADOS_PREENCHIDOS:
			SDL_FillRect(screen, &rect, cores[PRETO]);
			break;
		case MODO_QUADRADOS:
			(*drawObj).drawRect(screen, rect.x, rect.y, rect.w, rect.h, cores[PRETO]);
			break;
		case MODO_CIRCULOS:
			(*drawObj).drawCircle(screen, rect.x, rect.y, rect.w/2, cores[PRETO],false);
			break;
	}

	return 1;
}

int Unidade::attack(Unidade * inimigo)
{
	//80% da forca mais 20% da forca vezes um numero aleatorio de 1 a 10
	int ataque = 0.8 * forca 			+ 0.2 * forca * (*randomObj).gerarNumero(10);
	int defesa = 0.8 * (*inimigo).forca + 0.2 * (*inimigo).forca * (*randomObj).gerarNumero(10);

	if(ataque > defesa){
		(* inimigo).isDead = true;		
	}
	else
		isDead = true;

	return 1;
}

