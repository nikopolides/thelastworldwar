#include "Territorio.h"

Territorio::Territorio()
{
  nacao = NULL;
}

void Territorio::coletar()
{
  int petroleo = 5, ferro = 5, ouro = 5, madeira = 5;
  int bonusBase = 5, bonusEspecial = 15;

  //iterar todos e ir acumulando para a nacao
  for(list<Tile *>::iterator it = tiles.begin(); it != tiles.end(); it++)
  {
    switch( (*(*it)).tipo )
    {
      case OCEANO:      //agua
        petroleo += bonusBase;
        ouro += bonusBase;
        break;
      case TERRA:       //terra
        ferro += bonusBase;
        madeira += bonusBase;
        break;
      case FLORESTA:      //arvore
        madeira += bonusEspecial;
        break;
      case MINA_OURO:     //ouro
        ouro += bonusEspecial;
        break;
      case PETROLEO:      //petroleo
        petroleo += bonusEspecial;
        break;
      case MINA_FERRO:    //ferro
        ferro += bonusEspecial;
        break;
      default:        //capital dah mais recursos?
        break;        
    }
  }

  (*nacao).petroleo += petroleo;
  (*nacao).ferro += ferro;
  (*nacao).ouro += ouro;
  (*nacao).madeira += madeira;
}

void Territorio::serConquistado(Nacao* _nacao)
{
  nacao = _nacao;
  (*nacao).territorios.push_back(this);
}

void Territorio::addTile(Tile* tile)
{
  tiles.push_back(tile);
  (*tile).territorio = this;
}

void Territorio::mostrarCapital()
{
  (*tiles.front()).showCapital();
}

