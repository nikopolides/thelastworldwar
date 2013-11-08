#include "Nacao.h"

#define AVIAO 0
#define NAVIO 1
#define SOLDADO 2
#define CANHAO 3



Nacao::Nacao(int _petroleo, int _madeira, int _ouro, int _ferro, string _nome)
{
	petroleo = _petroleo;
	madeira = _madeira;
	ouro = _ouro;
	ferro = _ferro;

	nome = _nome;
	
	qtdNacao[0] = 0;
	qtdNacao[1] = 0;
	qtdNacao[2] = 0;
	qtdNacao[3] = 0;


}

void Nacao::contarExercito()
{	
	int i;
	
	for(i=0;i<4;i++)
		qtdNacao[i] = 0;	
	
	for(list<Unidade *>::iterator it1 = exercito.begin(); it1 != exercito.end(); it1++)
	{
		if ((*(*it1)).isDead)
			continue;

		switch ((*(*it1)).tipo)
		{
			case SOLDADO: 
					qtdNacao[SOLDADO]++;   
			break;

			case NAVIO: 
					qtdNacao[NAVIO]++;   
			break;

			case CANHAO: 
					qtdNacao[CANHAO]++;   
			break;
	
			case AVIAO: 
					qtdNacao[AVIAO]++;   
			break;

		}
				
	}

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
	
	contarExercito();
}

void Nacao::exercitoPop()
{
	exercito.pop_front();
}


void Nacao::carregaScore()
{
	SDL_Color textColor = {255, 255, 255, 255};
	
	sprintf(scoreRecursosNacao1,"%s -> Madeira: %d Ferro: %d Ouro: %d Petroleo: %d",nome.c_str(),madeira,ferro,ouro,petroleo);
	
	sprintf(scoreUnidadesNacao1,"%s -> Soldado: %d Navio: %d Canhao: %d Aviao: %d",nome.c_str(),qtdNacao[SOLDADO],qtdNacao[NAVIO],qtdNacao[CANHAO],qtdNacao[AVIAO]);

	messageRecursos = TTF_RenderText_Solid( font, scoreRecursosNacao1,textColor );
	messageUnidades = TTF_RenderText_Solid( font, scoreUnidadesNacao1,textColor );

}
