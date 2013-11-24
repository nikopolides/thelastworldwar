all:
	g++ -g `sdl-config --cflags --libs` server.cpp -Wall -W -pedantic -ansi -lSDL -lSDL_image -lSDL_ttf -lSDL_net -o server

	g++ -g `sdl-config --cflags --libs` LastWorldWar.cpp Cenario.cpp Tile.cpp Unidade.cpp Random.cpp Draw.cpp ImageHandlerSDL.cpp biblioteca.cpp Network.cpp game.cpp -Wall -W -pedantic -ansi -lSDL -lSDL_image -lSDL_ttf -lSDL_net globals.cpp globalsGame.cpp Nacao.cpp Timer.cpp -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
