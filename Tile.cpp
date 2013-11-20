#include "Tile.h"
#include "Territorio.h"

Tile::Tile(int _posX, int _posY, int _tipo)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;

	ocupante = NULL;
	territorio = NULL;
}

void Tile::show()
{
	if(territorio != NULL)
	{
		SDL_Rect rectTile;

		rectTile.x = posX;
		rectTile.y = posY;
		rectTile.w = 30;
		rectTile.h = 30;

//		SDL_SetAlpha(civilizationUnits, SDL_SRCALPHA, 100);

		if((*(*territorio).nacao).nome == "Estados Unidos")
			SDL_FillRect(screen, &rectTile, 0x0000FF);
		else if((*(*territorio).nacao).nome == "Siria")
			SDL_FillRect(screen, &rectTile, 0x00FF00);

//		SDL_SetAlpha(civilizationUnits, SDL_SRCALPHA, 100);
	}
//	SDL_FillRect(screen, &rectTile, cores[tipo]);
}
