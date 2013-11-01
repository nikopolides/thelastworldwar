all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp -W -Wall -pedantic -ansi -lSDL -lSDL_image -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
