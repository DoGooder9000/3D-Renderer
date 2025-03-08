#ifndef DRAW_H
#define DRAW_H

#include <SDL2/sdl.h>
#include "point.hpp"
#include "mesh.hpp"

void DrawPoint2D(SDL_Renderer* Renderer, Point2D point);
void DrawPoint3D(SDL_Renderer* Renderer, Point3D point);
void DrawLine2D(SDL_Renderer* Renderer, Point2D point1, Point2D point2);
void DrawLine3D(SDL_Renderer* Renderer, Point3D point1, Point3D point2);
void DrawTriangle2D(SDL_Renderer* Renderer, Triangle2D tri);
void DrawTriangle3D(SDL_Renderer* Renderer, Triangle3D tri);
void DrawMesh2D(SDL_Renderer* Renderer, Mesh2D mesh);
void DrawMesh3D(SDL_Renderer* Renderer, Mesh mesh);

#endif