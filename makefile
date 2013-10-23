all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp game.cpp biblioteca.cpp globalsGame.cpp -lSDL -lSDL_image -W -Wall -pedantic -ansi -o LastWorldWar

clean:
	rm -rf LastWorldWar
