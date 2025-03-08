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

void Point3DtoPoint2D(Point3D* in, Point2D* out);
void Triangle3DtoTriangle2D(Triangle3D* in, Triangle2D* out);

#endif