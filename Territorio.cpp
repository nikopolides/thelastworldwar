#include "Territorio.h"

Territorio::Territorio()
{
	nacao = NULL;
}

void Territorio::coletar()
{
	//iterar todos e ir acumulando para a nacao
	for(list<Tile *>::iterator it = tiles.begin(); it != tiles.end(); it++)
	{
		if( (*(*it)).tipo == 1)
		{
			//(*nacao).petroleo += 100;
			(*nacao).ferro += 20;
			//(*nacao).ouro += 100;
			(*nacao).madeira += 20;
		}
	}
}

void Territorio::conquistar(Nacao* _nacao)
{
	nacao = _nacao;
}

void Territorio::addTile(Tile* tile)
{
	tiles.push_back(tile);
	(*tile).territorio = this;
}

