all:
	gcc -Wall -g emulator.c `pkg-config --cflags --libs sdl2` -o emulator