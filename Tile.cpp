#include "Tile.h"
#include "Territorio.h"
#include "Unidade.h"

SDL_Rect rectTile;

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

		rectTile.x = posX*30;
		rectTile.y = posY*30;
		rectTile.w = 30;
		rectTile.h = 30;


		SDL_FillRect(screen, &rectTile, (*(*territorio).nacao).cor);

	}
}

void Tile::showCapital()
{
	SDL_Rect rectTile;

	rectTile.x = posX*30;
	rectTile.y = posY*30;
	rectTile.w = 30;
	rectTile.h = 30;

	SDL_FillRect(screen, &rectTile, 0xFFFFFF);	
}
