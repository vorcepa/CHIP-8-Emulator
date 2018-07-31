#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event userInput;

	int GameLoop = 1;

	/* Possible new file or function? */
	FILE *pROM;
	size_t size;
	unsigned int *buffer;
	int i;

	pROM = fopen("b", "rb");
	fseek(pROM, 0, SEEK_END);
	size = ftell(pROM);
	fseek(pROM, 0, SEEK_SET);

	buffer = malloc(size);

	for (i = 0; i<size; i++){
		printf("%02x ", buffer[i]);
	}

	printf("\n");
	fclose(pROM);
	free(buffer);
	/* End possible new file or function */


	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow(
		"An SDL Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);

	if (window == NULL){
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	else{
		surface = SDL_GetWindowSurface(window);
	}

	while(GameLoop){
		SDL_UpdateWindowSurface(window);
		while(SDL_PollEvent(&userInput)){
			if(userInput.type == SDL_KEYUP){
				switch(userInput.key.keysym.sym){
					case SDLK_q:
						GameLoop = 0;
						break;
					default:
						break;
				}
			}
			if(userInput.type == SDL_QUIT){
				GameLoop = 0;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}