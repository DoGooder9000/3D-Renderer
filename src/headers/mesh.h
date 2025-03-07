#ifndef MESH_H
#define MESH_H

#include "point.h"
#include <vector>

typedef struct{
	Point3D points[3];
} Triangle;

typedef struct{
	std::vector<Triangle> triangles;
} Mesh;

#endif