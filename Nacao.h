#ifndef NACAO_H
#define NACAO_H
#include "Unidade.h" 
#include <list> 

class Nacao
{
	public: 
		list <Unidade*> exercito;

		int petroleo;
		int madeira;
		int ouro;
		int ferro;

		Nacao(int, int, int, int);
		void init();
		void exercitoAdd(Unidade *);
		void exercitoPop();
};

#endif
