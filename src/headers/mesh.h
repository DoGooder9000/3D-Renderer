#ifndef MESH_H
#define MESH_H

#include "point.h"
#include <vector>

typedef struct{
	Point2D points[3];
} Triangle2D;

typedef struct{
	Point3D points[3];
} Triangle3D;

typedef struct{
	std::vector<Triangle3D> triangles;
} Mesh;

typedef struct{
	std::vector<Triangle2D> triangles;
} Mesh2D;

void Point3DtoPoint2D(Point3D* in, Point2D* out);
void Triangle3DtoTriangle2D(Triangle3D* in, Triangle2D* out);
void Mesh3DtoMesh2D(Mesh* in, Mesh2D* out);

void CubeMesh(Mesh* out, Point3D corner, float width);
void MakeTriangle(Triangle3D* out, float point1x, float point1y, float point1z, float point2x, float point2y, float point2z, float point3x, float point3y, float point3z);

#endif