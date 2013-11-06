#include "Nacao.h"

#define AVIAO 0
#define NAVIO 1
#define SOLDADO 2
#define CANHAO 3

Nacao::Nacao(int _petroleo, int _madeira, int _comida, int _ferro)
{
	petroleo = _petroleo;
	madeira = _madeira;
	comida = _comida;
	ferro = _ferro;

}

void Nacao::exercitoAdd(Unidade* unidade)
{

	if( (*unidade).tipo == AVIAO)
	{
		if(petroleo < 200 || ferro < 200) 
		{
			printf("Não há recursos o suficiente para criacao do AVIAO");		
		}
			else 
			{
				petroleo -= 200;
				ferro -= 200;
		
				exercito.push_back(unidade);
			}

	}

	if( (*unidade).tipo == NAVIO)
	{
		if(petroleo < 200 || ferro < 200) 
		{
			printf("Não há recursos o suficiente para criacao do NAVIO");		
		}
			else 
			{
				petroleo -= 200;
				ferro -= 200;
		
				exercito.push_back(unidade);
			}	
	}	

	if( (*unidade).tipo == SOLDADO)
	{
			if(comida < 200) 
		{
			printf("Não há recursos o suficiente para criacao do SOLDADO");		
		}
			else 
			{
				comida -= 200;

				exercito.push_back(unidade);
			}		
	}	

	if( (*unidade).tipo == CANHAO)
	{
		if(ferro < 200 || madeira < 200 ) 
		{
			printf("Não há recursos o suficiente para criacao do CANHAO");		
		}
			else 
			{
				ferro -= 200;
				madeira -= 200;		
	
				exercito.push_back(unidade);
			}	
	}


}

void Nacao::exercitoPop()
{
	exercito.pop_front();
}
