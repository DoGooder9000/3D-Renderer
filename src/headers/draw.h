#ifndef DRAW_H
#define DRAW_H

#include <SDL2/sdl.h>
#include "point.h"
#include "mesh.h"

void DrawPoint2D(SDL_Renderer* Renderer, Point2D point);
void DrawPoint3D(SDL_Renderer* Renderer, Point3D point);
void DrawTriangle(SDL_Renderer* Renderer, Triangle tri);
void DrawMesh(SDL_Renderer* Renderer, Mesh mesh);

#endif