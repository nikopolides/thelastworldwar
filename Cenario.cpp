#include "Cenario.h"

Cenario::Cenario(int _numeroTilesX, int _numeroTilesY)
{
	numeroTilesX = _numeroTilesX;
	numeroTilesY = _numeroTilesY;

	tiles = NULL;
}

int Cenario::initialize(int **tipos)
{
	tiles = (Tile***) calloc(numeroTilesY*numeroTilesX, sizeof(Tile**));

	for(int i = 0; i<numeroTilesY; i++)
	{
		tiles[i] = (Tile**) calloc(numeroTilesX, sizeof(Tile*));
		for(int j = 0; j<numeroTilesX; j++)
		{
			tiles[i][j] = new Tile(i,j,tipos[i][j]);
		}
	}
	
	if(tiles)
		return -1;

	if(tiles[numeroTilesY-1])
		return -2;

	return 1;
}

int Cenario::finalize()
{
	for(int i = 0; i<numeroTilesY; i++)
	{
		for(int j = 0; j<numeroTilesX; j++)
		{
			delete( tiles[i][j] );
		}
		free(tiles[i]);
	}
	free(tiles);

	return 1;
}

