#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
	public:
		int posX;
		int posY;
		int tipo;
		void* ocupante;

		Tile(int _posX, int _posY, int _tipo);
};

#endif
