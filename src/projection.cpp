#include "headers/projection.hpp"

Projector::Projector(){
	Projector::InitProjMat();
}

void Projector::InitProjMat(){
	proj_mat.matrix[0][0] = fAspectRatio * fFOVRad;
	proj_mat.matrix[1][1] = fFOVRad;
	proj_mat.matrix[2][2] = fFar / (fFar - fNear);
	proj_mat.matrix[3][3] = (-fFar * fNear) / (fFar - fNear);
	proj_mat.matrix[2][3] = 1;
	proj_mat.matrix[3][3] = 0;
}

void Projector::Project(Point3D* in, Point3D* out){
	out->x = in->x * proj_mat.matrix[0][0] + in->y * proj_mat.matrix[1][0] + in->z * proj_mat.matrix[2][0] + proj_mat.matrix[3][0];
	out->y = in->x * proj_mat.matrix[0][1] + in->y * proj_mat.matrix[1][1] + in->z * proj_mat.matrix[2][1] + proj_mat.matrix[3][1];
	out->z = in->x * proj_mat.matrix[0][2] + in->y * proj_mat.matrix[1][2] + in->z * proj_mat.matrix[2][2] + proj_mat.matrix[3][2];
	float w = in->x * proj_mat.matrix[0][3] + in->y * proj_mat.matrix[1][3] + in->z * proj_mat.matrix[2][3] + proj_mat.matrix[3][3];

	if (w != 0.0f){
		out->x /= w;
		out->y /= w;
		out->z /= w;
	}
}

void Projector::ProjectTriangle(Triangle3D* in, Triangle3D* out){
	Project(&(in->points[0]), &(out->points[0]));
	Project(&(in->points[1]), &(out->points[1]));
	Project(&(in->points[2]), &(out->points[2]));
}

void Projector::ProjectMesh(Mesh* in, Mesh* out){
	out->triangles.clear();

	for (Triangle3D tri : in->triangles){
		Triangle3D projected_triangle;

		ProjectTriangle(&tri, &projected_triangle);

		out->triangles.push_back(projected_triangle);
	}
}

void Projector::ScalePoint2D(Point2D* in, Point2D* out){
	out->x = in->x;
	out->y = in->y;

	out->x += 1.0f;
	out->y += 1.0f;

	out->x *= 0.5f * (float)WINDOW_WIDTH;
	out->y *= 0.5f * (float)WINDOW_HEIGHT;
}

void Projector::ScaleTriangle(Triangle3D* in, Triangle2D* out){
	Triangle2D temp_tri;
	Triangle3DtoTriangle2D(in, &temp_tri);

	ScalePoint2D(&(temp_tri.points[0]), &(out->points[0]));
	ScalePoint2D(&(temp_tri.points[1]), &(out->points[1]));
	ScalePoint2D(&(temp_tri.points[2]), &(out->points[2]));
}

void Projector::ScaleMesh(Mesh* in, Mesh2D* out){
	out->triangles.clear();

	Triangle2D temp_tri;

	for (Triangle3D tri : in->triangles){
		ScaleTriangle(&tri, &temp_tri);
		out->triangles.push_back(temp_tri);
	}
}

void Projector::TranslatePoint(Point3D* in, Point3D* out, float x, float y, float z){
	out->x = in->x + x;
	out->y = in->y + y;
	out->z = in->z + z;
}

void Projector::TranslateTriangle(Triangle3D* in, Triangle3D* out, float x, float y, float z){
	TranslatePoint(&(in->points[0]), &(out->points[0]), x, y, z);
	TranslatePoint(&(in->points[1]), &(out->points[1]), x, y, z);
	TranslatePoint(&(in->points[2]), &(out->points[2]), x, y, z);
}

void Projector::TranslateMesh(Mesh* in, Mesh* out, float x, float y, float z){
	out->triangles.clear();

	Triangle3D temp_tri;

	for (Triangle3D tri : in->triangles){
		TranslateTriangle(&tri, &temp_tri, x, y, z);
		out->triangles.push_back(temp_tri);
	}
}