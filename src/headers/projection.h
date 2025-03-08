#ifndef PROJ_H
#define PROJ_H

#include "matrix.h"
#include "settings.h"
#include "mesh.h"

class Projector{
	public:
		Matrix4x4 proj_mat;

		Projector();
		void Project(Point3D* in, Point3D* out);
		void ProjectTriangle(Triangle3D* in, Triangle3D* out);
		void ProjectMesh(Mesh* in, Mesh* out);

		void ScalePoint2D(Point2D* in, Point2D* out);
		void ScaleTriangle(Triangle3D* in, Triangle2D* out);
	
	private:
		void InitProjMat();
};

#endif