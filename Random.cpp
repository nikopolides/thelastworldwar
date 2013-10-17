class Random
{
	public:
		Random();
		int gerarNumero(int);
};

Random::Random()
{
	srand(time(NULL));
}

int Random::gerarNumero(int limit)
{
	return (rand() % limit) +1;		//retorna de 1 ateh o limite informado
}
