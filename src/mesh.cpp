#include "headers/mesh.hpp"

void Point3DtoPoint2D(Point3D* in, Point2D* out){
	out->x = in->x;
	out->y = in->y;
}

void Triangle3DtoTriangle2D(Triangle3D* in, Triangle2D* out){
	Point3DtoPoint2D(&(in->points[0]), &(out->points[0]));
	Point3DtoPoint2D(&(in->points[1]), &(out->points[1]));
	Point3DtoPoint2D(&(in->points[2]), &(out->points[2]));
}

void Mesh3DtoMesh2D(Mesh* in, Mesh2D* out){
	out->triangles.clear();

	Triangle2D temp_tri;

	for (Triangle3D tri : in->triangles){
		Triangle3DtoTriangle2D(&tri, &temp_tri);
		out->triangles.push_back(temp_tri);
	}
}

void CubeMesh(Mesh* out, Point3D corner, float width){
	out->triangles.clear();

	Triangle3D temp_tri;

	//Top Face
	MakeTriangle(&temp_tri, 
		corner.x, 		corner.y, 		corner.z, 
		corner.x+width, corner.y, 		corner.z, 
		corner.x, 		corner.y, 		corner.z + width);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x+width,	corner.y,		corner.z + width, 
		corner.x,		corner.y,		corner.z + width, 
		corner.x+width,	corner.y, 		corner.z);
	out->triangles.push_back(temp_tri);

	// Front Face
	MakeTriangle(&temp_tri,
		corner.x,		corner.y,		corner.z,
		corner.x, 		corner.y+width, corner.z, 
		corner.x+width, corner.y,		corner.z);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x+width,	corner.y+width,	corner.z, 
		corner.x+width,	corner.y,		corner.z, 
		corner.x,		corner.y+width,	corner.z);
	out->triangles.push_back(temp_tri);

	// Left Face
	MakeTriangle(&temp_tri,
		corner.x,		corner.y,		corner.z,
		corner.x, 		corner.y,		corner.z+width, 
		corner.x, 		corner.y+width,	corner.z);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x,	corner.y+width,	corner.z+width, 
		corner.x,	corner.y+width,	corner.z, 
		corner.x,	corner.y,		corner.z+width);
	out->triangles.push_back(temp_tri);

	
	// Back Side
	corner = Point3D{corner.x+width, corner.y+width, corner.z+width};
	width = -width;

	MakeTriangle(&temp_tri, 
		corner.x, 		corner.y, 		corner.z, 
		corner.x+width, corner.y, 		corner.z, 
		corner.x, 		corner.y, 		corner.z + width);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x+width,	corner.y,		corner.z + width, 
		corner.x,		corner.y,		corner.z + width, 
		corner.x+width,	corner.y, 		corner.z);
	out->triangles.push_back(temp_tri);

	MakeTriangle(&temp_tri,
		corner.x,		corner.y,		corner.z,
		corner.x, 		corner.y+width, corner.z, 
		corner.x+width, corner.y,		corner.z);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x+width,	corner.y+width,	corner.z, 
		corner.x+width,	corner.y,		corner.z, 
		corner.x,		corner.y+width,	corner.z);
	out->triangles.push_back(temp_tri);

	MakeTriangle(&temp_tri,
		corner.x,		corner.y,		corner.z,
		corner.x, 		corner.y,		corner.z+width, 
		corner.x, 		corner.y+width,	corner.z);
	out->triangles.push_back(temp_tri);
	MakeTriangle(&temp_tri, 
		corner.x,	corner.y+width,	corner.z+width, 
		corner.x,	corner.y+width,	corner.z, 
		corner.x,	corner.y,		corner.z+width);
	out->triangles.push_back(temp_tri);
}

void MakeTriangle(Triangle3D* out, float point1x, float point1y, float point1z, float point2x, float point2y, float point2z, float point3x, float point3y, float point3z){
	Point3D temp_point;

	temp_point.x = point1x; temp_point.y = point1y; temp_point.z = point1z;
	out->points[0] = temp_point;
	
	temp_point.x = point2x; temp_point.y = point2y; temp_point.z = point2z;
	out->points[1] = temp_point;
	
	temp_point.x = point3x; temp_point.y = point3y; temp_point.z = point3z;
	out->points[2] = temp_point;
}