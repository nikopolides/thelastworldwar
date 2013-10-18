all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp Cenario.cpp Tile.cpp -Wall -W -pedantic -ansi -lSDL -lSDL_image -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
