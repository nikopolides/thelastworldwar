#ifndef NACAO_H
#define NACAO_H
#include "Unidade.h" 
#include "Territorio.h"
#include <list> 

class Nacao
{
	public: 
		list <Unidade*> exercito;
		list <Territorio*> territorios;
		
		int petroleo;
		int madeira;
		int ouro;
		int ferro;
		int energia;
	
		int qtdNacao[4];

		string nome;
		Uint32 cor;

		Nacao(int, int, int, int, string, Uint32);
		void init();
		void exercitoAdd(Unidade *);
		void exercitoPop();		
		void carregaScore();
		void contarExercito();
		int contarTerritorios();
		void coletar();
};

#endif
