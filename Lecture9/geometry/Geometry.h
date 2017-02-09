#pragma once
#ifndef _H_GEOMETRY_EP
#define _H_GEOMETRY_EP


// Loads objects to test against
#include "tiny_obj_loader.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cassert>
#include <vector>
//Include Eigen for matrix functionality.
#include <Eigen/Dense>
//#define __aligned(...)           __declspec(align(__VA_ARGS__))
typedef Eigen::Matrix<uint32_t, Eigen::Dynamic, Eigen::Dynamic> MatrixXu;


namespace Geometry
{
	class Geometry
	{
	public:
		Geometry();
		virtual ~Geometry();

		unsigned int LoadOBJFile_Triangles(const char* filename, const char* basepath = NULL, bool triangulate = true, Eigen::Vector4f &intialization_color = Eigen::Vector4f(-1.0f, -1.0f, -1.0f, -1.0f));

		void set_mGeometry(Eigen::MatrixXf & pGeometry);
		void set_mColors(Eigen::MatrixXf & pColors);
		void set_mUvs(Eigen::MatrixXf & pUVs);
		void set_mNormals(Eigen::MatrixXf & pNormals);
		void set_mGeometry_indices(MatrixXu & pGeometry_indices);


		Eigen::MatrixXf & get_mGeometry( void );
		Eigen::MatrixXf & get_mColors( void );
		Eigen::MatrixXf & get_mUvs( void );
		Eigen::MatrixXf & get_mNormals( void );
		MatrixXu & get_mGeometry_indices( void );


		void getAABB(Eigen::Vector3f &minBB, Eigen::Vector3f &maxBB);
		float getBoundingRadius(Eigen::Vector3f &minBB, Eigen::Vector3f &maxBB);

		void UpdateColorAtIndex(unsigned int column, Eigen::Vector4f &new_color);
		void UpdatePositionAtIndex(unsigned int column, Eigen::Vector3f &new_pos);

		void UpdateColorAtCol(unsigned int column, Eigen::Vector4f &new_color);
		void UpdatePositionAtCol(unsigned int column, Eigen::Vector3f &new_pos);


		//helper access methods (faster and reduce verbosity when accessing individual elements)
		Eigen::Vector3f getVertex(int index) { return Eigen::Vector3f(mGeometry(3 * index + 0), mGeometry(3 * index + 1), mGeometry(3 * index + 2)); }
		unsigned int getTotalNumberOfTriangles(void) { return (unsigned int)(mGeometry_indices.size() / 3); }
		unsigned int getTriangleVertexIndex(int triangle, int vert) { return mGeometry_indices(3*triangle+vert); }
		Eigen::Vector3f getTriangleVertex(int triangle, int vert) { return getVertex(getTriangleVertexIndex(triangle,vert)); }
		Eigen::Vector3f getTriangleNormal(int triangle);
		float getTriangleArea(int triangle, Eigen::Vector3f *outTriangleNormal=NULL);


	protected:
		//Vertex data structures
		Eigen::MatrixXf  mGeometry; //Vertex Geometry x, y, z coords
		Eigen::MatrixXf  mUvs; //Vertex UV coordinates
		Eigen::MatrixXf  mNormals; //Vertex Normals
		//Triangle data structures
		MatrixXu  mGeometry_indices; //Triangle vertex index array (three vertex indices per triangle)
		Eigen::MatrixXf  mColors; //Triangle colors (currently as r,g,b,a or 4 channels per triangle)

	};
}

#endif

