#pragma once
#ifndef _H_AXISLINES
#define _H_AXISLINES

#include "helper.hpp"


namespace Visualizer
{
	class AxisLines : public Geometry::Geometry
	{
	public:
		AxisLines();
		~AxisLines();
		void Visualize(Eigen::Matrix4f &mvp);
		void VisualizeWireFrame();
	//private:
		nanogui::GLShader mShader;
	};
}

#endif