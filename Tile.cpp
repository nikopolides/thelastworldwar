#include "Tile.h"

SDL_Rect rectTile;

Tile::Tile(int _posX, int _posY, int _tipo)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;

	ocupante = NULL;
}

void Tile::show()
{
	rectTile.x = posX;
	rectTile.y = posY;
	rectTile.x = 30;
	rectTile.y = 30;

	//cout << "foi " << tipo << endl;

	SDL_FillRect(screen, &rect, cores[tipo]);
}
