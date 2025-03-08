#include "headers/matrix.h"

void MultiplyMatrix4x4(Point3D* point1, Point3D* point2, Matrix4x4 mat){
	point2->x = point1->x * mat.matrix[0][0] + point1->y * mat.matrix[1][0] + point1->z * mat.matrix[2][0] + mat.matrix[3][0];
	point2->y = point1->x * mat.matrix[0][1] + point1->y * mat.matrix[1][1] + point1->z * mat.matrix[2][1] + mat.matrix[3][1];
	point2->z = point1->x * mat.matrix[0][2] + point1->y * mat.matrix[1][2] + point1->z * mat.matrix[2][2] + mat.matrix[3][2];
	float w = point1->x * mat.matrix[0][3] + point1->y * mat.matrix[1][3] + point1->z * mat.matrix[2][3] + mat.matrix[3][3];

	if (w != 0.0f){
		point2->x /= w;
		point2->y /= w;
		point2->z /= w;
	}
}