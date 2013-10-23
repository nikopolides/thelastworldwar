#include "Tile.h"

Tile::Tile(int _posX, int _posY, int _tipo)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;

	ocupante = NULL;
}
