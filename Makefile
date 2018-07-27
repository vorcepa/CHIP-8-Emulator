all:
	gcc -Wall -g untitled.c `pkg-config --cflags --libs sdl2` -o untitled