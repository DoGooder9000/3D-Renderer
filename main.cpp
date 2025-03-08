#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "src/headers/draw.h"
#include "src/headers/point.h"
#include "src/headers/settings.h"
#include "src/headers/mesh.h"
#include "src/headers/projection.h"

int Deltatime(int newtime, int oldtime);

int newtime, oldtime, deltatime;

int main(int argc, char* argv[]){
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Point3D CameraPos = {0, 0, 0};

	Projector projector;

	Mesh cube, translated_cube, projected_cube;
	Mesh2D scaled_cube;

	CubeMesh(&cube, Point3D{0, 0, 0}, 1);

	translated_cube.triangles = cube.triangles;

	/*
	projector.ProjectTriangle(&tri, &projected_tri);

	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[0].x, projected_tri.points[0].y, projected_tri.points[0].z);
	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[1].x, projected_tri.points[1].y, projected_tri.points[1].z);
	printf("X: %f, Y: %f, Z: %f\n", projected_tri.points[2].x, projected_tri.points[2].y, projected_tri.points[2].z);
	printf("%f\n", fFOVRad);

	projector.ScaleTriangle(&projected_tri, &scaled_tri);

	printf("X: %f, Y: %f\n", scaled_tri.points[0].x, scaled_tri.points[0].y);
	printf("X: %f, Y: %f\n", scaled_tri.points[1].x, scaled_tri.points[1].y);
	printf("X: %f, Y: %f\n", scaled_tri.points[2].x, scaled_tri.points[2].y);
	*/

	newtime = SDL_GetTicks();

	bool running = true;

	SDL_Event e;

	while (running){
		oldtime = newtime;
		newtime = SDL_GetTicks();
		deltatime = Deltatime(newtime, oldtime);
		
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}
		}

		// Keys
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

		if( currentKeyStates[ SDL_SCANCODE_W ] ){
			CameraPos.z += MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_S ] ){
			CameraPos.z += -MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_A ] ){
			CameraPos.x += -MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_D ] ){
			CameraPos.x += MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_E ] ){
			CameraPos.y += -MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_Q ] ){
			CameraPos.y += MoveSpeed*deltatime;
		}

		projector.TranslateMesh(&cube, &translated_cube, CameraPos.x, CameraPos.y, CameraPos.z);

		// Projecting
		projector.ProjectMesh(&translated_cube, &projected_cube);
		projector.ScaleMesh(&projected_cube, &scaled_cube);

		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		SDL_RenderClear(Renderer);

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		DrawMesh2D(Renderer, scaled_cube);

		SDL_RenderPresent(Renderer);
	}

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);

	SDL_Quit();

	return 0;
}

int Deltatime(int newtime, int oldtime){
	return (newtime-oldtime);
}