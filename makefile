all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp Cenario.cpp Tile.cpp Unidade.cpp Random.cpp Draw.cpp ImageHandlerSDL.cpp biblioteca.cpp game.cpp -Wall -W -pedantic -ansi -lSDL -lSDL_image globals.cpp globalsGame.cpp Nacao.cpp -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
