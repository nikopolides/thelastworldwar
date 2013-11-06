#ifndef TILE_H
#define TILE_H

#include "Draw.h"
#include "globals.h"
#include "globalsGame.h"
#include <iostream>

class Tile
{
	public:
		int posX;
		int posY;
		int tipo;
		void* ocupante;

		Tile(int _posX, int _posY, int _tipo);
		void show();
};

#endif
