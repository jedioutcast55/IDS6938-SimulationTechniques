#pragma once
#ifndef _H_MESH
#define _H_MESH

#include "helper.hpp"
#include "Geometry.h"


namespace Visualizer
{
	class Mesh : public Geometry::Geometry
	{
	public:
		Mesh();
		~Mesh();

		void Visualize(Eigen::Matrix4f &mvp, ToneMapping const * toneMap=NULL);
		void Visualize(Eigen::Matrix4f &mvp, unsigned int temp_pindex, unsigned int patch_triangle_count);
		void Visualize(Eigen::Matrix4f &mvp, const std::vector<int> &triangleIndices);
		void VisualizeWireFrame(Eigen::Matrix4f &mvp);
		void InitShaders(std::string name);
		void ChangeMeshColors();

		//private:
		nanogui::GLShader *mShader;
	};
}

#endif