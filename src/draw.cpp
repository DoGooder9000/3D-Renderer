#include "headers/draw.h"

void DrawPoint2D(SDL_Renderer* Renderer, Point2D point){
	SDL_RenderDrawPoint(Renderer, (int)point.x, (int)point.y);
}

void DrawPoint3D(SDL_Renderer* Renderer, Point3D point){
	SDL_RenderDrawPoint(Renderer, (int)point.x, (int)point.y);
}

void DrawLine2D(SDL_Renderer* Renderer, Point2D point1, Point2D point2){
	SDL_RenderDrawLine(Renderer, (int)point1.x, (int)point1.y, (int)point2.x, (int)point2.y);
}

void DrawLine3D(SDL_Renderer* Renderer, Point3D point1, Point3D point2){
	SDL_RenderDrawLine(Renderer, (int)point1.x, (int)point1.y, (int)point2.x, (int)point2.y);
}

void DrawTriangle2D(SDL_Renderer* Renderer, Triangle2D tri){
	DrawLine2D(Renderer, tri.points[0], tri.points[1]);
	DrawLine2D(Renderer, tri.points[1], tri.points[2]);
	DrawLine2D(Renderer, tri.points[2], tri.points[0]);
}

void DrawTriangle3D(SDL_Renderer* Renderer, Triangle3D tri){
	DrawLine3D(Renderer, tri.points[0], tri.points[1]);
	DrawLine3D(Renderer, tri.points[1], tri.points[2]);
	DrawLine3D(Renderer, tri.points[2], tri.points[0]);
}

void DrawMesh3D(SDL_Renderer* Renderer, Mesh mesh){
	for (Triangle3D tri : mesh.triangles){
		DrawTriangle3D(Renderer, tri);
	}
}

void DrawMesh2D(SDL_Renderer* Renderer, Mesh2D mesh){
	for (Triangle2D tri : mesh.triangles){
		DrawTriangle2D(Renderer, tri);
	}
}