all:
	g++ `sdl-config --cflags --libs` LastWorldWar.cpp -lSDL -lSDL_image -o LastWorldWar

init: LastWorldWar
	./LastWorldWar

clean:
	rm -rf LastWorldWar
