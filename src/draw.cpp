#include "headers/draw.h"

void DrawPoint2D(SDL_Renderer* Renderer, Point2D point){
	SDL_RenderDrawPoint(Renderer, point.x, point.y);
}

void DrawPoint3D(SDL_Renderer* Renderer, Point3D point){
	SDL_RenderDrawPoint(Renderer, point.x, point.y);
}

void DrawTriangle(SDL_Renderer* Renderer, Triangle tri){
	DrawPoint3D(Renderer, tri.points[0]);
	DrawPoint3D(Renderer, tri.points[1]);
	DrawPoint3D(Renderer, tri.points[2]);
}

void DrawMesh(SDL_Renderer* Renderer, Mesh mesh){
	for (Triangle tri : mesh.triangles){
		DrawTriangle(Renderer, tri);
	}
}