#pragma once

#ifndef _H_GRIDLINES
#define _H_GRIDLINES

#include "helper.hpp"


namespace Visualizer
{
	class GridLines : public Geometry::Geometry
	{
	public:
		GridLines();
		~GridLines();

		void Visualize(Eigen::Matrix4f &mvp);
		void VisualizeWireFrame();
	//private:
		nanogui::GLShader mShader;
	};
}

#endif