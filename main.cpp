#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "src/headers/draw.h"
#include "src/headers/point.h"
#include "src/headers/settings.h"
#include "src/headers/mesh.h"

int main(int argc, char* argv[]){
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Mesh mesh;

	mesh.triangles = {{{0.0f, 0.0f, 0.0f}, {0.0f, 100.0f, 0.0f}, {100.0f, 0.0f, 0.0f}}};

	bool running = true;

	SDL_Event e;
	while (running){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}
		}

		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		SDL_RenderClear(Renderer);

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		DrawMesh(Renderer, mesh);

		SDL_RenderPresent(Renderer);
	}

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);

	SDL_Quit();

	return 0;
}