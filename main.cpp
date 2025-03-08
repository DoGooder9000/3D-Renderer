#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "src/headers/draw.h"
#include "src/headers/point.h"
#include "src/headers/settings.h"
#include "src/headers/mesh.h"
#include "src/headers/projection.h"

int main(int argc, char* argv[]){
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Projector projector;

	Triangle3D tri, projected_tri;
	Triangle2D scaled_tri;

	tri.points[0] = {0.0f, 0.0f, 10.0f};
	tri.points[1] = {1.0f, 0.0f, 10.0f};
	tri.points[2] = {0.0f, 1.0f, 10.0f};

	projector.ProjectTriangle(&tri, &projected_tri);

	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[0].x, projected_tri.points[0].y, projected_tri.points[0].z);
	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[1].x, projected_tri.points[1].y, projected_tri.points[1].z);
	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[2].x, projected_tri.points[2].y, projected_tri.points[2].z);
	printf("%f\n", fFOVRad);

	projector.ScaleTriangle(&projected_tri, &scaled_tri);

	printf("X: %f, Y: %f\n", scaled_tri.points[0].x, scaled_tri.points[0].y);
	printf("X: %f, Y: %f\n", scaled_tri.points[1].x, scaled_tri.points[1].y);
	printf("X: %f, Y: %f\n", scaled_tri.points[2].x, scaled_tri.points[2].y);

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
		DrawTriangle2D(Renderer, scaled_tri);

		SDL_RenderPresent(Renderer);
	}

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);

	SDL_Quit();

	return 0;
}