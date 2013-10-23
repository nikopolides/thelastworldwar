#include "Nacao.h"


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
}

void Nacao::exercitoPop()
{
	exercito.pop_front();
}
