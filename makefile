all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp -Wall -w -ansi -lSDL -lSDL_image -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
