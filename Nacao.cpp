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
	exercito.push_back(unidade);

	if( (*unidade).tipo == AVIAO)
	{
		petroleo -= 200;
		ferro -= 200;
	}

	if( (*unidade).tipo == NAVIO)
	{
		petroleo -= 200;
		ferro -= 200;	
	}	

	if( (*unidade).tipo == SOLDADO)
	{
		comida -= 200;	
	}	

	if( (*unidade).tipo == CANHAO)
	{
		madeira -= 200;
		ferro -= 200;	
	}

}

void Nacao::exercitoPop()
{
	exercito.pop_front();
}
