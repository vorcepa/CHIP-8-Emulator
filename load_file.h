#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define OFFSET 0x200
#define RAM_SIZE 4096
/*
Loads the file 'b', which is in the same folder as emulator.
This is a binary data file with 2 byte hex words.  Each of these
words is then stored in 'chip_mem', with each word broken up
in to individual bytes.  The RAM_SIZE is the number of bytes
a CHIP-8 device has available.  The OFFSET is where the game data
starts in memory.  0x0 to 0x1FF is where the interpreter is stored
in memory on the CHIP-8 hardware.

TO DO: Pass in or send load_file the file the user wants to load
(to make n number of games available for the user to play).
*/
int load_file(char rom){
	FILE *pROM;
	size_t size;
	uint8_t chip_mem[RAM_SIZE] = {0};
	int i;

	pROM = fopen("b", "rb");
	fseek(pROM, 0, SEEK_END);
	size = ftell(pROM); // set to the length of the binary file that is read, in # of characters
	fseek(pROM, 0, SEEK_SET);

	size = fread(chip_mem+OFFSET, 1, size, pROM);

	for (i = 0; i < RAM_SIZE; i++){
		if (chip_mem[i]){
			printf("%i: %x\n", i, chip_mem[i]);
		}
	}

	printf("\n");
	fclose(pROM);

	return 0;
}