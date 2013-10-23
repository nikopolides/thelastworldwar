all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp game.cpp -lSDL -lSDL_image -o LastWorldWar

clean:
	rm -rf LastWorldWar
