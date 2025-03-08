#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "src/headers/draw.hpp"
#include "src/headers/point.hpp"
#include "src/headers/settings.hpp"
#include "src/headers/mesh.hpp"
#include "src/headers/projection.hpp"

int Deltatime(int newtime, int oldtime);
float FPS(int deltatime);

int newtime, oldtime, deltatime;
char window_title[20];

int main(int argc, char* argv[]){
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	Point3D CameraPos = {0, 0, -10};

	Projector projector;

	Mesh WorldMesh, translated, projected;
	Mesh2D scaled;

	Mesh cube;

	for (float i=0; i<10; i++){
		for (float j=0; j<1; j++){
			for (float k=0; k<10; k++){
				CubeMesh(&cube, Point3D{i, j, k}, 1);
				WorldMesh.triangles.insert( WorldMesh.triangles.end(), cube.triangles.begin(), cube.triangles.end() );
			}
		}
	}

	translated.triangles = WorldMesh.triangles;


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
		if( currentKeyStates[ SDL_SCANCODE_SPACE ] ){
			CameraPos.y += -MoveSpeed*deltatime;
		}
		if( currentKeyStates[ SDL_SCANCODE_LSHIFT ] ){
			CameraPos.y += MoveSpeed*deltatime;
		}

		projector.TranslateMesh(&WorldMesh, &translated, -CameraPos.x, -CameraPos.y, -CameraPos.z);

		// Projecting
		projector.ProjectMesh(&translated, &projected);
		projector.ScaleMesh(&projected, &scaled);

		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		SDL_RenderClear(Renderer);

		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		DrawMesh2D(Renderer, scaled);

		SDL_RenderPresent(Renderer);

		snprintf(window_title, sizeof(window_title), "FPS: %.2f", FPS(deltatime));
		SDL_SetWindowTitle(Window, window_title);
	}

	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);

	SDL_Quit();

	return 0;
}

int Deltatime(int newtime, int oldtime){
	return (newtime-oldtime);
}

float FPS(int deltatime){
	if (deltatime != 0){
		return 1000.f / (float)deltatime;
	}

	return 1000.f;
}