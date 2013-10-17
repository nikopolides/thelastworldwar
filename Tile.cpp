
class Tile
{
	public:
		int posX;
		int posY;
		int tipo;
		void* ocupante;

		Tile(int, int, int);
};

Tile::Tile(int _posX, int _posY, int _tipo)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;

	ocupante = NULL;
}
