#include "headers/mesh.h"

void Point3DtoPoint2D(Point3D* in, Point2D* out){
	out->x = in->x;
	out->y = in->y;
}

void Triangle3DtoTriangle2D(Triangle3D* in, Triangle2D* out){
	Point3DtoPoint2D(&(in->points[0]), &(out->points[0]));
	Point3DtoPoint2D(&(in->points[1]), &(out->points[2]));
	Point3DtoPoint2D(&(in->points[1]), &(out->points[2]));
}