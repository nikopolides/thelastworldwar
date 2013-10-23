#ifndef CENARIO_H
#define CENARIO_H

#include "Tile.h"
#include <cstdlib>

class Cenario
{
	public:
		int numeroTilesX;
		int numeroTilesY;
		Tile ***tiles;

		Cenario(int _numeroTilesX, int _numeroTilesY);
		int initialize(int **tipos);
		int finalize();
};

#endif
