#ifndef MATRIX_H
#define MATRIX_H

#include "point.hpp"

typedef struct{
	float matrix[4][4] = {0};
} Matrix4x4;

void MultiplyMatrix4x4(Point3D* point1, Point3D* point2, Matrix4x4 mat);

#endif