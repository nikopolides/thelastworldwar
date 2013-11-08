#include "Nacao.h"

#define AVIAO 0
#define NAVIO 1
#define SOLDADO 2
#define CANHAO 3

Nacao::Nacao(int _petroleo, int _madeira, int _ouro, int _ferro)
{
	petroleo = _petroleo;
	madeira = _madeira;
	ouro = _ouro;
	ferro = _ferro;

}

void Nacao::exercitoAdd(Unidade* unidade)
{

	if( (*unidade).tipo == AVIAO)
	{
		if(petroleo < 100 || ferro < 100 || ouro < 100 || madeira < 100) 
		{
			printf("Não há recursos o suficiente para criacao do AVIAO");		
		}
			else 
			{
				petroleo -= 100;
				ferro -= 100;
				ouro -= 100;
				madeira -= 100;
		
				exercito.push_back(unidade);
			}

	}

	if( (*unidade).tipo == NAVIO)
	{
		if(petroleo < 100 || ferro < 100 || ouro < 50 || madeira < 100) 
		{
			printf("Não há recursos o suficiente para criacao do NAVIO");		
		}
			else 
			{
				petroleo -= 100;
				ferro -= 100;
				ouro -= 50;
				madeira -= 100;
		
				exercito.push_back(unidade);
			}	
	}	

	if( (*unidade).tipo == SOLDADO)
	{
			if(ferro < 50 || ouro < 50) 
		{
			printf("Não há recursos o suficiente para criacao do SOLDADO");		
		}
			else 
			{
				ouro -= 50;
				ferro -= 50;
	
				exercito.push_back(unidade);
			}		
	}	

	if( (*unidade).tipo == CANHAO)
	{
		if(ferro < 200 || madeira < 100 || ouro < 50 ) 
		{
			printf("Não há recursos o suficiente para criacao do CANHAO");		
		}
			else 
			{
				ferro -= 100;
				madeira -= 100;						
				ouro -= 50;	

				exercito.push_back(unidade);
			}	
	}


}

void Nacao::exercitoPop()
{
	exercito.pop_front();
}

void Nacao::carregaScore()
{
	SDL_Color textColor = {255, 255, 255, 255};
	
	sprintf(scoreRecursosNacao1,"Nacao1 -> Madeira: %d Ferro: %d Ouro: %d Petroleo: %d",madeira,ferro,ouro,petroleo);
	
	sprintf(scoreUnidadesNacao1,"Nacao1 -> Soldado: %d Navio: %d Canhao: %d Aviao: %d",qtdNacao1[0],qtdNacao1[1],qtdNacao1[2],qtdNacao1[3]);

	messageRecursos = TTF_RenderText_Solid( font, scoreRecursosNacao1,textColor );
	messageUnidades = TTF_RenderText_Solid( font, scoreUnidadesNacao1,textColor );

}
