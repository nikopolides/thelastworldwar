#ifndef TERRITORIO_H
#define TERRITORIO_H

#include "Tile.h"
#include "Nacao.h"
#include "globals.h"
#include "globalsGame.h"
#include <iostream>
#include <list> 

class Territorio
{
  public:
    list <Tile*> tiles;
    Nacao* nacao;

    Territorio();
    void coletar();
    void serConquistado(Nacao* _nacao);
    void addTile(Tile* tile);
    void mostrarCapital();
};

#endif
