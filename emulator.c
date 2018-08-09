#include <stdio.h>
#include <SDL2/SDL.h>
#include "load_file.h"

int main(int argc, char* argv[]){
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event userInput;

	int GameLoop = 1;
	char rom = 'b';

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

	load_file(rom);

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