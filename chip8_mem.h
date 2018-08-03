#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

/* 
Currently: chip8_mem.c loads the ROM file (a binary file with 2 byte
long hex values), and now I am working on implementing it such that 
all of the data from that file is stored in elements of an array 
that acts as the CHIP-8's RAM.

Also I need to link this file to emulator.c, which is the main file
that will be ran by the user.

TO DO: Possibly break up loading the file and storing values in to
memory as separate files?
*/
int load_file(char rom){
	FILE *pROM;
	size_t size;
	unsigned char *buffer;
	int i;

	pROM = fopen("b", "rb");
	fseek(pROM, 0, SEEK_END);
	size = ftell(pROM);
	fseek(pROM, 0, SEEK_SET);

	buffer = malloc(size);

	size = fread(buffer, 1, size, pROM);

	for (i = 0; i<size - 1; i+=2){
		printf("%02x%02x ", buffer[i], buffer[i + 1]);
	}

	printf("\n");
	fclose(pROM);
	free(buffer);

	return 0;
}