#ifndef NACAO_H
#define NACAO_H
#include "Unidade.h"
#include "FontHandler.h" 
#include <list> 

class Nacao
{
	public: 
		list <Unidade*> exercito;

		int petroleo;
		int madeira;
		int ouro;
		int ferro;

	
		int qtdNacao[4];

		string nome;

		Nacao(int, int, int, int, string);
		void init();
		void exercitoAdd(Unidade *);
		void exercitoPop();		
		void carregaScore();
		void contarExercito();
};

#endif
