enum {
	AVIAO,
	NAVIO,
	SOLDADO,
	CANHAO
};

class Unidade
{
	public:
		int posX;	//tile X do mapa onde atualmente habita
		int posY;	//tile Y do mapa onde atualmente habita
		int tipo;	//aviao,navio,soldado,canhao,etc...
		
		Unidade(int, int, int);
		int show();
};

Unidade::Unidade(int _posX, int _posY, int _tipo)
{
	posX = _posX;
	posY = _posY;
	tipo = _tipo;
}
int Unidade::show()
{
	if(tipo == SOLDADO)
	{
		rect.x = 30*0;
		rect.y = 30*0;
	}
	if (tipo == NAVIO)
	{
		rect.x = 30*0;
		rect.y = 32*4+1;
	}
	
	rect.w = 30;
	rect.h = 30;	

	apply_surface( posX*30, posY*30, civilizationUnits, screen, &rect);


	/*rect.x = posX*30;
	rect.y = posY*30;
	rect.w = 30;
	rect.h = 30;

	SDL_FillRect(screen, &rect, 0x000000);*/	

	return 1;
}
